package ptit.practice_3.rmi._character;
import RMI.CharacterService;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry("203.162.10.109", 1099);

        CharacterService service = (CharacterService) registry.lookup("RMICharacterService");

        String data = service.requestCharacter("B22DCCN866", "B0eAtQvW");

        System.out.println(data);
        int []f = new int[1000000];
        String request = "{";
        for (int i = 0; i < data.length(); i++) f[data.charAt(i)]++;
        for (int i = 0; i < data.length(); i++) {
            if (f[data.charAt(i)] != 0) {
                request += "\"" + data.charAt(i) + "\": " + f[data.charAt(i)] + ", ";
                f[data.charAt(i)] = 0;
            }
        }
        request = request.substring(0, request.length() - 2) + "}";
        service.submitCharacter("B22DCCN866", "B0eAtQvW", request);
    }
}
