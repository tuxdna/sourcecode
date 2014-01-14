package org.tuxdna.rmi;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;

public class RmiServer extends UnicastRemoteObject implements RmiServerIntf {
  private static final long serialVersionUID = 1L;
  
  public static final String MESSAGE = "Hello world";
  
  public RmiServer() throws RemoteException {
    super(0); // required to avoid the 'mic' step, see below
  }
  
  public String getMessage() {
    return MESSAGE + " at: " + System.currentTimeMillis();
  }
  
  public static void main(String args[]) throws Exception {
    
    System.out.println("RMI server started");
    int rmiPort = 1100;
    
    try { // special exception handler for registry creation
      LocateRegistry.createRegistry(rmiPort);
      System.out.println("java RMI registry created.");
    } catch (RemoteException e) {
      // do nothing, error means registry already exists
      System.out.println("java RMI registry already exists.");
    }
    
    // Instantiate RmiServer
    RmiServer obj = new RmiServer();
    
    // Bind this object instance to the name "RmiServer"
    String locationName = "//localhost:" + rmiPort + "/RmiServer";
    Naming.rebind(locationName, obj);
    System.out.println("PeerServer bound in registry at " + locationName);
  }
}