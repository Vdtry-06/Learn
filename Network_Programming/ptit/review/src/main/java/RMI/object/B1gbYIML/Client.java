package RMI.object.B1gbYIML;

import RMI.ObjectService;
import RMI.Product;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    private static final String SERVER_HOST = "203.162.10.109";
    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry(SERVER_HOST);
        ObjectService service = (ObjectService) registry.lookup("RMIObjectService");

        Product product = (Product) service.requestObject("B22DCCN866", "B1gbYIML");
        product.updateCode();
        product.updateExportCode();

        service.submitObject("B22DCCN866", "B1gbYIML", product);
    }
}
