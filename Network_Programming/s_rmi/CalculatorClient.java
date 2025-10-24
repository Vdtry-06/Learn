package s_rmi;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

public class CalculatorClient {
    public static void main(String[] args) throws MalformedURLException, NotBoundException, RemoteException {
            Calculator cal = (Calculator) Naming.lookup("rmi://127.0.0.1/calx2");
            int sum = cal.add(150, 200);
            System.out.println("sum {from remote server}: " + sum);

    }
}
