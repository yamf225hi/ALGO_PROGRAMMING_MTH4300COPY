#include<vector>
#include<iostream>
#include <math.h> 
#include <limits>

using namespace std;

class Datapoint
{
    public:
    int x, y, t;

    Datapoint(int a, int b, int c) : x(a), y(b), t(c) {}
};

struct Replacement 
{
  int start;
  string before;
  string after; 

  Replacement(int s, string b, string a):start(s),before(b),after(a){}
};

string ReplaceInSourceCode(vector<Replacement> input, string sourceCode)
{
    string output = sourceCode;
    int shift = 0;
    for(auto& i : input)
    {
      string pre = output.substr(0, i.start + shift);
      string post = output.substr(i.start + shift + i.before.length());
      output = pre + i.after + post;
      shift = shift +  i.after.length() - i.before.length();
    }
  return output;
}

// Given a vector of datapoints where x and y and coordinates and t is time, 
// return the fastest time where 1 km(1000 m) is run by a runner. 
double GetFastestOneKM(vector<Datapoint> input)
{
    vector<double> distances;
    for (int i = 1; i < input.size(); i++)
    {
        double temp_x = pow(input[i].x - input[i-1].x,2);
        double temp_y = pow(input[i].y - input[i-1].y,2);
        double temp_dist = temp_x + temp_y;
        distances.push_back(sqrt(temp_dist));
    }

    double best_onekm = numeric_limits<double>::max();
    for(int i = 0; i < distances.size(); i++)
    {
        double sum = 0;    
        for(int j = i; j < distances.size(); j++)
        {
            double curr_secs = j - i + 1;
            sum = sum+distances[j];
            if(sum >=1000 && curr_secs< best_onekm)
            {
                best_onekm = curr_secs;
            }
        }
    }

    for (auto& a : distances)
        cout<<a<<endl;
    return best_onekm; 
}