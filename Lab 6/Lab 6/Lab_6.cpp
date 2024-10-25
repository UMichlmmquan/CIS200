#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

class DataPoint 
{
public:
    double x;
    double y;
    DataPoint* next;

    // Constructor
    DataPoint(double X, double Y) 
    {
        x = X;
        y = Y;
        next = nullptr;
    }
};

class DataSet
{
private:
    DataPoint* head;

public:
    // Constructor
    DataSet()
    {
        head = nullptr;
    }

    DataPoint* getHead()
    {
        return head;
    }

    // Destructor
    ~DataSet()
    {
        DataPoint* cur = head;
        while (cur != nullptr)
        {
            DataPoint* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // Insert a node at the beginning of the list:
    void insertFirstNode(double X, double Y)
    {
        DataPoint* newNode = new DataPoint(X,Y);
        newNode->next = head;
        head = newNode;
    }

    // Display the linked list
    void traverseList() 
    {
        cout << "Data Points: " << endl;
        for (DataPoint* cur = head; cur != nullptr; cur = cur->next) 
        {
            cout << "(" << cur->x << ", " << cur->y << ")" << endl;
        }
        cout << endl;
    }
};

class LinearCurveFitter
{
public:
    void fit(DataSet &data)
    {
        //Declare variables
        float sum_xy = 0;
        float sum_x = 0;
        float sum_y = 0;
        float sum_sqr_x = 0;
        int n = 0;
        //Traverse the list
        for (DataPoint* cur = data.getHead(); cur != nullptr; cur = cur->next)
        {
            //Calculating the sums
            sum_x += cur->x;
            sum_y += cur->y;
            sum_xy += cur->x * cur->y;
            sum_sqr_x += cur->x * cur->x;
            //Update the number of data points
            n++;
        }
        //Calculate the slope and intercept by applying the given formula
        slope = (n * sum_xy - sum_x * sum_y) / (n * sum_sqr_x - sum_x * sum_x);
        intercept = (sum_y - slope * sum_x) / n;
    }

    //Output the equation
    void displayEquation()
    {
        //I set the precision to 2
        cout << fixed << setprecision(2) << "Best Fit Line: y = " << slope << " * x + " << intercept << endl;
    }

    double predict(double X)
    {
        return slope * X + intercept;
    }
    
    void displayPredict(DataSet &data)
    {
        for (DataPoint* cur = data.getHead(); cur != nullptr; cur = cur->next)
        {
            cout << "Prediction for x = " << cur->x << ": " << predict(cur->x) << endl;
        }
    }

    void calculateRMSError(DataSet &data)
    {
        //Declare variable
        double sumSqError = 0;
        int n = 0;

        //Traverse the list
        for (DataPoint* cur = data.getHead(); cur != nullptr; cur = cur->next)
        {
            //Calculate the y - y^1
            double error = cur->y - predict(cur->x);
            //Calculate the sum error
            sumSqError += error * error;
            //Update the number of data points
            n++;
        }
        //Output the result
        cout <<  setprecision(6) << "RMS Error: " << sqrt(sumSqError / n) << endl;
    }

private:
    double slope;
    double intercept;
};

int main()
{
    //Declare variable
    DataSet subset;
    LinearCurveFitter line;

    //Add nodes
    subset.insertFirstNode(4, 7.8);
    subset.insertFirstNode(3, 5.8);
    subset.insertFirstNode(2, 3.9);
    subset.insertFirstNode(1, 2);

    //Display the input points
    subset.traverseList();

    //Calculate the best fit line
    line.fit(subset);
    //Display the result
    line.displayEquation();
    //Display the prediction for all x
    line.displayPredict(subset);
    //Calculate and display the RMS Error
    line.calculateRMSError(subset);

    system("pause");
    return 0;
}