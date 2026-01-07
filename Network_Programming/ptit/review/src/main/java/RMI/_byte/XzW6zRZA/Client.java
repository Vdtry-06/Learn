package RMI._byte.XzW6zRZA;

import RMI.ByteService;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    public static void main (String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry(SERVER_HOST, 1099);
        ByteService service = (ByteService) registry.lookup("RMIByteService");

        byte[] data = service.requestData("B22DCCN866", "XzW6zRZA");
        String hex = bytesToHex(data);
        System.out.println(hex);

        byte[] encode = hexToBytes(hex);
        System.out.println(encode);

        service.submitData("B22DCCN866", "XzW6zRZA", encode);

    }

    private static byte[] hexToBytes(String hex) {
        byte[] res = new byte[hex.length()];
        for (int i = 0; i < hex.length(); i++) {
            res[i] = (byte) hex.charAt(i);
        }
        return res;
    }

    private static String bytesToHex(byte[] arr) {
        String hex = "0123456789abcdef";
        StringBuilder sb = new StringBuilder();
        for (byte b : arr) {
            sb.append(hex.charAt(b / 16));
            sb.append(hex.charAt(b % 16));
        }
        return sb.toString();
    }
}
