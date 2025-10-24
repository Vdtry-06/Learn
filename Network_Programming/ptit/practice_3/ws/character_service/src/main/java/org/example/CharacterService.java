package org.example;

import jakarta.jws.WebMethod;
import jakarta.jws.WebService;
import java.util.List;

@WebService(targetNamespace = "http://medianews.vn/")
public interface CharacterService {
    @WebMethod
    List<String> requestStringArray(String studentCode, String qCode);

    @WebMethod
    void submitCharacterStringArray(String studentCode, String qCode, List<String> data);
}