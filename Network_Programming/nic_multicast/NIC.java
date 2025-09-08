package nic_multicast;

import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;

public class NIC {
    public static void main(String[] args) throws SocketException {
        Enumeration<NetworkInterface> nifs = NetworkInterface.getNetworkInterfaces();
        while (nifs.hasMoreElements()) {
            NetworkInterface ni = nifs.nextElement();
            if (ni.isUp()) {
                System.out.println(ni);
            }
        }
    }
}
