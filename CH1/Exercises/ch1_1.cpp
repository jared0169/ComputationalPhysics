/*
	File: ch1_1.cpp
	
	Calculates the solution to dv/dt = -g using the Euler method 
	for t = 1 to t = 10 with varying sizes of time steps
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void initializeArray(double a[],int size){
	for (int i = 0; i < size; ++i){
		a[i] = 0;
	}
}

double calculateV(double v, double dt, double g){
	v -= g*dt;
	return v;
}

void storeData(double time[], double v_numeric[], int size, double dt){
	string filename;
	
	cout << "Please enter a filename (including extension): ";
	cin >> filename;
	
	ofstream f;
	f.open(filename.c_str(),ios::out);
	f << "time,v_numeric,dt=" << dt << endl;
	for (int i = 0; i < size; ++i){
		f << time[i] << "," << v_numeric[i] << endl;
	}
	f.close();
}


int main(){
	int steps;
	double v,dt,t_initial,t_final,g,t;
	
	// Sets the values for t_initial and t_final, and g at 9.8 m/s^2
	// initial velocity is 0
	g = 9.8;
	t_initial = 1.0;
	t_final = 10.0;
	v = 0;
	
	// Gets the number of steps between 1s and 10s, and calculates
	// the step size
	cout << "Enter the number of steps: ";
	cin >> steps;
	
	dt = (t_final - t_initial) / steps;

	double velocity[steps];
	//double v_actual[steps];
	double time[steps];
	
	initializeArray(velocity,steps);
	initializeArray(time,steps);
	
	velocity[0] = v;
	time[0] = t_initial;
	//v_actual[0] = v;
	t = t_initial;
	
	for (int i = 1; i < steps; ++i){
		v = calculateV(v,dt,g);
		t += dt;
		velocity[i] = v;
		//v_actual[i] = -g*t;
		time[i] = t;
	}
	
	//cout << "T_final = " << time[steps-1] << endl;
	
	storeData(time,velocity,steps,dt);
	
	return 0;
}