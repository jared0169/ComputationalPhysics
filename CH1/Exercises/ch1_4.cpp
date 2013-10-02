/*
	File: ch1_4.cpp
	
	Solves the differential equations:
		1.) dN_a/dt = -N_a/tau_a
		2.) dN_b/dt = N_a/tau_a - N_b/tau_b
	
	Explores different values for tau_a/tau_b
*/

#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <fstream>
#include <string>

using namespace std;

void initializeArray(double a[], int size){
	for (int i = 0; i < size; ++i){
		a[i] = 0;
	}
}

double calculateN_a(double n_a, double tau_a, double dt){
	n_a -= (n_a / tau_a) * dt;
	return n_a;
}

double calculateN_b(double n_a, double n_b, double tau_a, double tau_b, double dt){
	n_b += ((n_a / tau_a) - (n_b / tau_b)) * dt;
	return n_b;
}

void storeData(double time[], double a[], double tau_a, double b[], double tau_b, int size){
	string filename;
	
	cout << "Enter a filename: ";
	cin >> filename;
	
	ofstream f;
	f.open(filename.c_str(),ios::out);
	f << "time,nuclei_a,nuclei_b,tau_a=" << tau_a << ",tau_b="<< tau_b << endl;
	for (int i = 0; i < size; ++i){
		f << time[i] << "," << a[i] << "," << b[i] << endl;
	}
	f.close();
}

void calculateData(double tau_a, double tau_b){
	int steps = 10000;
	double time[steps],nuclei_a[steps],nuclei_b[steps];
	
	initializeArray(nuclei_a,steps);
	initializeArray(nuclei_b,steps);
	initializeArray(time,steps);
	
	double n_a = 1000, n_b = 1000, t_initial = 0.0, t_final = 10.0;
	double dt = (t_final - t_initial) / steps;
	double t = t_initial;
	
	nuclei_a[0] = n_a;
	nuclei_b[0] = n_b;
	time[0] = t_initial;
	
	for (int i = 1; i < steps; ++i){
		n_a = calculateN_a(n_a,tau_a,dt);
		n_b = calculateN_b(n_a,n_b,tau_a,tau_b,dt);
		t += dt;
		nuclei_a[i] = n_a;
		nuclei_b[i] = n_b;
		time[i] = t;
	}
	
	storeData(time,nuclei_a,tau_a,nuclei_b,tau_b,steps);
}

int main(){
	double tau_a, tau_b;
	bool stopRunning = false;
	char answer;
	
	do
	{
		cout << "Please enter the time constant tau_a: ";
		cin >> tau_a;
		cout << "Please enter the time constant tau_b: ";
		cin >> tau_b;
		
		calculateData(tau_a,tau_b);
		
		cout << "Continue? (y/n): ";
		cin >> answer;
		if (answer == 'n' || answer == 'N'){
			stopRunning = true;
		}
	}while(!stopRunning);
	

	return 0;
}