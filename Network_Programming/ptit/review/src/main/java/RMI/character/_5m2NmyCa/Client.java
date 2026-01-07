package RMI.character._5m2NmyCa;

import RMI.CharacterService;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry(SERVER_HOST);

        CharacterService service = (CharacterService) registry.lookup("RMICharacterService");
        String data = service.requestCharacter("B22DCCN866", "5m2NmyCa");
        int [] f = new int[256];

        for (int i = 0; i < data.length(); i++) {
            f[data.charAt(i)]++;
        }
        StringBuilder s = new StringBuilder();

        for (int i = 0; i < data.length(); i++) {
            if (f[data.charAt(i)] != 0) {
                s.append(data.charAt(i));
                s.append(f[data.charAt(i)]);
                f[data.charAt(i)] = 0;
            }
        }

        System.out.println(s);

        service.submitCharacter("B22DCCN866", "5m2NmyCa", s.toString());
    }
}
