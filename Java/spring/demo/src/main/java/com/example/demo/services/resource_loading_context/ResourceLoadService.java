package com.example.demo.services.resource_loading_context;

import org.springframework.core.io.Resource;
import org.springframework.core.io.ResourceLoader;
import org.springframework.stereotype.Component;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

@Component
public class ResourceLoadService {
    private final ResourceLoader resourceLoader;

    public ResourceLoadService(ResourceLoader resourceLoader) {
        this.resourceLoader = resourceLoader;
    }

    public void readFile(String filePath) throws IOException {
        Resource resource = resourceLoader.getResource("classpath:" + filePath);

        String ext = getExtension(filePath);
        switch (ext) {
            case "txt":
                readText(resource);
                break;

            case "png":
            case "jpg":
            case "jpeg":
                readImage(resource);
                break;

            case "json":
                readJson(resource);
                break;

            case "bin":
            case "zip":
            case "pdf":
                readBinary(resource);
                break;

            default:
                System.out.println("No help to read file: " + ext);
        }
    }

    private String getExtension(String fileName) {
        int index = fileName.lastIndexOf('.');
        if (index == -1) return "";
        return fileName.substring(index + 1).toLowerCase();
    }

    private void readText(Resource resource) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(resource.getInputStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            System.out.println(line);
        }
    }

    private void readImage(Resource resource) throws IOException {
        BufferedImage image = ImageIO.read(resource.getInputStream());
        System.out.println("Image: " + image.getWidth() + "x" + image.getHeight());
        System.out.printf(image.getData().toString());
    }

    private void readBinary(Resource resource) throws IOException {
        byte[] bytes = resource.getInputStream().readAllBytes();
        System.out.println("Readed: " + bytes.length + " bytes");
    }

    private void readJson(Resource resource) throws IOException {
        String json = new String(resource.getInputStream().readAllBytes());
        System.out.println("Json content: " + json);
    }
}
