package org.tuxdna.rmi;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IAddition extends Remote {
	public int add(int a, int b) throws RemoteException;
}
