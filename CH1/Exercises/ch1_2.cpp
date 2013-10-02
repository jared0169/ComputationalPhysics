/*
	File: ch1_2.cpp
	
	Solves for x(t) using the Euler method of integration
	for dx/dt = v.
*/

#include <iostream>
#include <fstream>

using namespace std;

void initializeArray(double a[], int size){
	for (int i = 0; i < size; ++i){
		a[i] = 0;
	}
}

double calculateX(double x, double v, double dt){
	x += v*dt;
	return x;
}

int main(){

	int steps = 10000;
	double t_initial = 0.0, t_final = 1.0;
	double x, dt, t, v;
	
	v = 40.0;
	x = 0.00;
	t = t_initial;
	dt = (t_final - t_initial) / steps;
	
	double position[steps];
	double time[steps];
	
	initializeArray(position,steps);
	initializeArray(time,steps);
	
	position[0] = x;
	time[0] = t;

	for (int i = 1; i < steps; ++i){
		x = calculateX(x,v,dt);
		t += dt;
		position[i] = x;
		time[i] = t;
	}
	
	cout << "The position after 1.0s is: " << position[steps-1] << endl;
	
	return 0;
}