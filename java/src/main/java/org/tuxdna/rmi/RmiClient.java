package org.tuxdna.rmi;
import java.net.InetAddress;
import java.rmi.Naming;

public class RmiClient {
  public static void main(String args[]) throws Exception {
    int rmiPort = 1100;
    
    System.out.println(InetAddress.getLocalHost().getHostName());
    String locationName = "//localhost:" + rmiPort + "/RmiServer";
    locationName = args[0];
    RmiServerIntf obj = (RmiServerIntf) Naming.lookup(locationName);
    for (int i = 0; i < 10; i++)
      System.out.println(obj.getMessage());
  }
}
