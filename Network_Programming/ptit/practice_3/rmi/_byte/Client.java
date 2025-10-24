package ptit.practice_3.rmi._byte;

import RMI.ByteService;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry("203.162.10.109", 1099);

        ByteService service = (ByteService) registry.lookup("RMIByteService");

        byte[] data = service.requestData("B22DCCN866", "c5MhibgU");

        System.out.println(new String(data));

        byte[] encode = new byte[data.length];
        for (int i = 0; i < data.length; i++) {
            encode[i] = (byte) (data[i] + data.length);
        }
        System.out.println(new String(encode));

        service.submitData("B22DCCN866", "c5MhibgU", encode);
    }
}
