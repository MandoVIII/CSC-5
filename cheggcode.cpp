#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int readNumOfDataPairs(string );
void fileData(string , double* , double* );
void calcSumProductSquare(double *, double *, int , double &, double &, double &, double &);
double calcSlope(double *, double *, int );
double calcYIntercept(double *, double *, int );
double calcStdDev(double *, int );
void leastSqLinesEqu(double , double );

// main function
int main()
{
    string filename;

    double *temperature;
    double *resistance;

    cout << "Enter the filename: ";
    getline(cin , filename);
    int size = readNumOfDataPairs(filename);

    if(size == -1)
    {
        cin.clear();
        cin.ignore();
        return -1;
    }

    temperature = new double[size];
    resistance = new double[size];

    fileData(filename, temperature, resistance);

    // calculating slope
    double slope = calcSlope(temperature, resistance, size);

    // calculating y intercept
    double yIntercept = calcYIntercept(temperature, resistance, size);

    leastSqLinesEqu(slope, yIntercept);

    //temperature standard deviation
    double tempStd = calcStdDev(temperature, size);

    //resistance standard deviation
    double resistStd = calcStdDev(resistance, size);

    cout << "-----------------------------------------" << endl;
    cout << "Standard Deviation of Temperature(x) = " << tempStd << endl;
    cout << "Standard Deviation of Resistance(y) = " << resistStd << endl;
}

// function to read number of data pairs
int readNumOfDataPairs(string filename)
{
    ifstream infile;
    infile.open(filename.c_str());
    if(!infile)
    {
        cout << "Error! File not found" << endl;
        return -1;
    }
    double data;
    int count = 0;
    while(!infile.eof())
    {
        infile >> data;
        infile >> data;
        count++;
    }
    infile.close();
    return count;
}

// function for getting data pairs
void fileData(string filename, double *temp, double *resist)
{
    ifstream infile(filename.c_str());
    int ind = 0;
    while(!infile.eof())
    {
        infile >> *(temp + ind);
        infile >> *(resist + ind);
        ind++;
    }
    infile.close();
}


// function for x and y values calculations
void calcSumProductSquare(double *temp, double *resist, int size, double &sum_x, double &sum_y, 
        double &sqSum_x, double &sum_xyProd)
{
    for(int i = 0; i < size; i++)
    {
        double t, r;
        t = *(temp + i);
        r = *(resist + i);
        sum_x = sum_x + t;
        sum_y = sum_y + r;
        sqSum_x = sqSum_x + (t * t);
        sum_xyProd = sum_xyProd + (t * r);
    }
}

// function for slope
double calcSlope(double *temp, double *resist, int size)
{
    double sum_x = 0;
    double sum_y = 0;
    double sqSum_x = 0;
    double sum_xyProd = 0;
    calcSumProductSquare(temp, resist, size, sum_x, sum_y, sqSum_x, sum_xyProd);
    double avg_y = (sum_y / size);
    double avg_x = sum_x / size;
    double slope = ( sum_xyProd - (sum_x * avg_y) )/( sqSum_x - (sum_x * avg_x) );
    return slope;
}

// function to calculate and return the y intercept
double calcYIntercept(double *temp, double *resist, int size)
{
    double sum_x = 0;
	double sum_y = 0;
    double sqSum_x = 0;
    double sum_xyProd = 0;
    calcSumProductSquare(temp, resist, size, sum_x, sum_y,sqSum_x, sum_xyProd);
    double slope = calcSlope(temp, resist, size);
    double y_intercept = ( (sum_y * sqSum_x) - (sum_x * sum_xyProd) ) /( size*(sqSum_x) - pow(sum_x, 2) );
    return y_intercept;
}

// function to calculate and return the standard deviation
double calcStdDev(double *data, int size)
{
    double mean = 0;
    for(int i = 0; i < size; i++)
    {
        mean = mean + *(data + i);
    }
    mean /= size;

    double sq_diff = 0;
    for(int i = 0; i < size; i++)
    {
        sq_diff = sq_diff + pow( (*(data + i) - mean), 2);
    }
    sq_diff = sq_diff / (size - 1);
    return sqrt(sq_diff);
}

// function to display the equation of least square
void leastSqLinesEqu(double slope, double yIntercept)
{
    cout << "Equation of least squares line: y = " << slope <<
 "x" << " + " << yIntercept << endl;
}
