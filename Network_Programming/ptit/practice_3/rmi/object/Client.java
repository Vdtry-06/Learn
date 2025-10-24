package ptit.practice_3.rmi.object;
import RMI.ObjectService;
import RMI.ProductX;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry("203.162.10.109", 1099);

        ObjectService service = (ObjectService) registry.lookup("RMIObjectService");
        ProductX productX = (ProductX) service.requestObject("B22DCCN866", "GDi9b5z7");
        productX.updateDiscount();

        service.submitObject("B22DCCN866", "GDi9b5z7", productX);
    }
}
