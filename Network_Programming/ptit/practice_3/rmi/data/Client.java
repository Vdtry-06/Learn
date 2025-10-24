package ptit.practice_3.rmi.data;
import RMI.DataService;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.List;

public class Client {
    public static void main(String[] args) throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry("203.162.10.109", 1099);

        DataService service = (DataService) registry.lookup("RMIDataService");

        Integer amount = (Integer) service.requestData("B22DCCN866", "d9MzZt2p");
        System.out.println(amount);

        int[] coins = {10, 5, 2, 1};
        List<Integer> list = new ArrayList<>();
        int tmp = amount;
        int s = 0;
        for (int c : coins) {
            int cnt = tmp / c;
            if (cnt > 0) {
                s += cnt;
                tmp %= c;
                for (int i = 0; i < cnt; i++) list.add(c);
            }
            if (tmp == 0) break;
        }

        String request = s + "; ";

        for (int n : list) {
            request += n + ",";
        }
        request = request.substring(0, request.length() - 1);

        service.submitData("B22DCCN866", "d9MzZt2p", request);
    }
}
