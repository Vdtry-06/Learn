package Code_PTIT.Bai7;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class App extends JFrame {
    private JTable table;
    private DefaultTableModel tableModel;
    private ArrayList<Item> items;

    public App() {
        setTitle("ClassSection Exercises with JTable");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Khởi tạo model của bảng và bảng
        tableModel = new DefaultTableModel();
        tableModel.setColumnIdentifiers(new String[]{"ID", "Name", "Value"});
        table = new JTable(tableModel);

        JScrollPane scrollPane = new JScrollPane(table);

        // Các nút bấm
        JButton btnReadFile = new JButton("Read Files from Directory");
        JButton btnSort = new JButton("Sort");

        // Tạo panel chứa các nút bấm
        JPanel panel = new JPanel();
        panel.add(btnReadFile);
        panel.add(btnSort);

        // Thêm các thành phần vào JFrame
        add(scrollPane, BorderLayout.CENTER);
        add(panel, BorderLayout.SOUTH);

        items = new ArrayList<>();

        // Gán hành động cho các nút bấm
        btnReadFile.addActionListener(this::readFilesFromDirectory);
        btnSort.addActionListener(this::sortItems);
    }

    // Phương thức đọc file từ thư mục đã chọn
    private void readFilesFromDirectory(ActionEvent event) {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
        int option = fileChooser.showOpenDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File directory = fileChooser.getSelectedFile();
            File[] files = directory.listFiles();

            if (files != null) {
                int idCounter = items.size() + 1; // Bắt đầu ID từ số lượng hiện tại

                for (File file : files) {
                    if (file.isFile()) {
                        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                            StringBuilder content = new StringBuilder();
                            String line;
                            while ((line = br.readLine()) != null) {
                                content.append(line).append("\n");
                            }

                            // Tạo một Item mới và thêm vào danh sách cũng như bảng
                            Item item = new Item(String.valueOf(idCounter++), file.getName(), content.toString());
                            items.add(item);
                            tableModel.addRow(new Object[]{item.getId(), item.getName(), item.getValue()});
                        } catch (IOException e) {
                            JOptionPane.showMessageDialog(this, "Error reading file: " + e.getMessage());
                        }
                    }
                }
            }
        }
    }

    // Phương thức sắp xếp danh sách các item theo tên và cập nhật JTable
    private void sortItems(ActionEvent event) {
        // Sắp xếp các item theo tên
        Collections.sort(items, Comparator.comparing(Item::getName));

        // Xóa và điền lại bảng với danh sách các item đã sắp xếp
        tableModel.setRowCount(0);
        for (Item item : items) {
            tableModel.addRow(new Object[]{item.getId(), item.getName(), item.getValue()});
        }
    }
}