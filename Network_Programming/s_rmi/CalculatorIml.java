package s_rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class CalculatorIml extends UnicastRemoteObject implements Calculator {

    // create constructor
    public CalculatorIml() throws RemoteException {
        super();
    }

    @Override
    public int add(int a, int b) throws RemoteException {
        System.out.println("Add request: (a=" + a + ", b=" + b + ")");
        return a + b;
    }
}
