# File: decay_plot.py
#
# Takes the csv data produced by decay.cpp and plots it

import pylab
import csv

def main():
    try:
        f = open("decay.csv","r")
        f_dict = csv.DictReader(f)
    except:
        print "Error: No such file 'decay.csv' exists"
     
    t = []
    n_numerical = []
    n_actual = []
    for row in f_dict:
        t.append(float(row["time"]))
        n_numerical.append(float(row["uranium_numerical"]))
        n_actual.append(float(row["uranium_actual"]))

    pylab.plot(t,n_numerical)
    pylab.plot(t,n_actual)
    pylab.show()


if __name__ == "__main__":
    main()
