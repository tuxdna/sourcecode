package org.tuxdna.rmi;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Addition extends UnicastRemoteObject implements IAddition {
	private static final long serialVersionUID = 1L;

	public Addition() throws RemoteException {
		// TODO Auto-generated constructor stub
	}

	public int add(int a, int b) {
		return a + b;
	}
}
