/*
	File: ch1_3.cpp
	
	Solves dv/dt = a - bv using Euler method. 
*/

#include <iostream>
#include <fstream>
#include <cmath>
//#include "array_funcs.h"

using namespace std;


void initializeArray(double a[], int size){
	for (int i = 0; i < size; ++i){
		a[i] = 0;
	}
}

double calculateV(double v, double dt, double a, double b){
	v += (a - b*v) * dt;
	return v;
}

void storeData(double time[], double v_numeric[],double v_actual[], double dt, int size){
	
	string filename;
	
	cout << "Enter a filename: ";
	cin >> filename;
	
	ofstream f;
	f.open(filename.c_str(),ios::out);
	f << "time,v_numeric,v_actual,dt=" << dt << endl;
	for (int i = 0; i < size; ++i){
		f << time[i] << "," << v_numeric[i] << "," << v_actual[i] << endl;
	}
	f.close();
}

int main(){
	int steps = 10000;
	
	double v, dt, a, b, t_final, t;
	double t_initial = 0.0;
	
	double velocity[steps];
	double time[steps];
	double v_actual[steps];
	
	initializeArray(&velocity,steps);
	initializeArray(&time,steps);
	initializeArray(&v_actual,steps);
	
	a = 10.0;
	b = 1.0;
	
	cout << "Enter final time: ";
	cin >> t_final;
	
	t = t_initial;
	dt = (t_final - t_initial) / steps;
	
	velocity[0] = 0.0;
	v_actual[0] = 0.0;
	time[0] = t;
	
	for (int i = 1; i < steps; ++i){
		v = calculateV(v,dt,a,b);
		t += dt;
		velocity[i] = v;
		v_actual[i] = a/b - (a/b)*exp(-b*t); 
		time[i] = t;
	}
	
	storeData(time,velocity,v_actual,dt,steps);
	
	return 0;
}