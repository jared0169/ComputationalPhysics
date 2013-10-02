/*
	File: decay.cpp
	
	This C++ program accompanies chapter 1 of Computational Physics by N. Giordano. 
	
	Simulation of radioactive decay. 
	
	Implements the Euler method for solving ODEs to solve the differential
	equation for radioactive decay: dN/dt = -N(t)/tau
*/

#include <iostream>
#include <cmath>
#include <fstream> // Writing to file
#include <string>

using namespace std;

/* 
	Using the Taylor expansion: N(t + delta_t) = N(t) + (dN/dt)*delta_t

	From the underlying physics of radioactive decay, dN/dt = -N(t)/tau.
	
*/

void initializeArray(double a[],int size){
	for (int i = 0; i < size; ++i){
		a[i] = 0;
	}
}

double calcNuclei(double n, double dt, double tau){
	n -= (n/tau) * dt;
	return n;
}

void storeData(double time[], double a_numerical[], double a_actual[], int length,double tau,double dt){
	
	string filename;
	
	cout << "Please enter a filename: ";
	cin >> filename;
	
	ofstream f;
	f.open(filename.c_str(),ios::out);
	f << "time,uranium_numerical,uranium_actual,tau="<< tau << ",dt="<<dt<< endl;
	for (int i = 0; i < length; ++i){
		f << time[i] << "," << a_numerical[i] << "," << a_actual[i] << endl;
	}
	f.close();
	
}

int main(){
	int steps = 1000; // Sets the amount of steps needed. 
	/*
		n   => number of nuclei
		t   => time
		dt  => time step delta t
		tau => decay time constant
	*/
	double n,n_0,dt,t,tau,t_final;
	
	/*
		declares the two arrays that will hold the output of both
		the nuclei at time t, and the time.
	*/
	double uranium_nuclei[steps];
	double uranium_actual[steps];
	double time[steps];
	
	string filename;
	
	initializeArray(uranium_nuclei,steps);
	initializeArray(time,steps);
	initializeArray(uranium_actual,steps);
	/*
		Deprecated code: Used to test whether arrays were actually
		initialized
		
	for (int i = 0; i < steps; ++i){
		cout << "Element " << i << ": " << uranium_nuclei[i]<<endl;
	}
	*/
	
	
	cout << "Enter the initial number of nuclei: ";
	cin >> n_0;
	cout << "Enter the initial time: ";
	cin >> t;
	cout << "Enter the final time: ";
	cin >> t_final;
	cout << "Enter the time constant, tau: ";
	cin >> tau;
	/* 
		--- NOT CURRENTLY USED --- 
			Can be used to give more control to the user.
			
	cout << "Enter the number of steps: ";
	cin >> steps;
	*/
	
	n = n_0;
	uranium_nuclei[0] = n;
	uranium_actual[0] = n;
	time[0] = t;

	dt = t_final / steps; 
	
	// Loops through calculating the number of uranium nuclei
	for (int i = 1; i < steps; ++i){
		n = calcNuclei(n,dt,tau);
		t += dt;
		uranium_nuclei[i] = n;
		uranium_actual[i] = n_0 * exp(-t/tau);
		time[i] = t;
	}
	
	
	storeData(time,uranium_nuclei,uranium_actual,steps,tau,dt);
	
	return 0;
}