package org.tuxdna.rmi;
import java.net.MalformedURLException;
import java.rmi.*;

public class AdditionClient {
	public static void main(String[] args) {
		String remoteHostName = "box01";
		int remotePort = 1091;
		String connectLocation = "//" + remoteHostName + ":" + remotePort
				+ "/Hello";

		IAddition hello = null;
		try {
			System.out.println("Connecting to client at : " + connectLocation);
			hello = (IAddition) Naming.lookup(connectLocation);
		} catch (MalformedURLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (RemoteException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (NotBoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		int result = 0;
		try {
			result = hello.add(9, 10);
		} catch (RemoteException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		System.out.println("Result is :" + result);

	}
}
