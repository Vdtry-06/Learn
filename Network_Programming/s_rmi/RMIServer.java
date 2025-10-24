package s_rmi;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class RMIServer {
    public static void main(String[] args) throws MalformedURLException, RemoteException {
        LocateRegistry.createRegistry(1099);
        System.out.println("RMI Server started...");

        CalculatorIml cal = new CalculatorIml();
        Naming.rebind("rmi://127.0.0.1:/calx2", cal);

        System.out.println("RMI Calculator Server is running");
    }
}
// có thể run = câu lệnh: rmi rmiregistry