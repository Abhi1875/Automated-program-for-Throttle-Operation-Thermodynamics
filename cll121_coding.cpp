#include<bits/stdc++.h>
using namespace std;
#define N 23
#define n 7
void interpolate_H(double P, double T, double x, vector<double> &values, vector<vector<double>>P_1, vector<vector<double>>P_4, vector<vector<double>>P_6){ 
    if(P==0.1){
        for(int i=0; i<N; i++){
            if(i != N-1 && P_1[i][0]==T && P_1[i+1][0]==T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    double k;
                    if(j==1 || j==2){
                       k=(1-x)*(1/P_1[i][j])+x*(1/P_1[i+1][j]);
                       k=1/k;
                    }
                    else{
                        k=(1-x)*(P_1[i][j])+x*P_1[i+1][j];
                    }                    
                    values.push_back(k);
                }
                break;
            }
            else if(P_1[i][0]==T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(P_1[i][j]);
                }
                break;
            }
            else if(P_1[i][0]<T && P_1[i+1][0]>T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(P_1[i][j]+(((T-P_1[i][0])/(P_1[i+1][0]-P_1[i][0]))*(P_1[i+1][j]-P_1[i][j])));
                }
                break;
            }
            else if(i==N-1){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(-1);
                }
                break;
            }
        }      
    }
    else if(P==1.4){
        for(int i=0; i<N; i++){
            if(i != N-1 && P_4[i][0]==T && P_4[i+1][0]==T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    double k;
                    if(j==1 || j==2){
                       k=(1-x)*(1/P_4[i][j])+x*(1/P_4[i+1][j]);
                       k=1/k;
                    }
                    else{
                        k=(1-x)*(P_4[i][j])+x*P_4[i+1][j];
                    }
                    values.push_back(k);
                }
                break;
            }
            else if(P_4[i][0]==T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(P_4[i][j]);
                }
                break;
            }
            else if(P_4[i][0]<T && P_4[i+1][0]>T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(P_4[i][j]+(((T-P_4[i][0])/(P_4[i+1][0]-P_4[i][0]))*(P_4[i+1][j]-P_4[i][j])));
                }
                break;
            }
            else if(i==N-1){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(-1);
                }
                break;
            }
        }
        
    }
    else if(P==1.6){
        for(int i=0; i<N; i++){
            if(i != N-1 && P_6[i][0]==T && P_6[i+1][0]==T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    double k;
                    if(j==1 || j==2){
                       k=(1-x)*(1/P_6[i][j])+x*(1/P_6[i+1][j]);
                       k=1/k;
                    }
                    else{
                        k=(1-x)*(P_6[i][j])+x*P_6[i+1][j];
                    }
                    values.push_back(k);
                }
                break;
            }
            else if(P_6[i][0]==T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(P_6[i][j]);
                }
                break;
            }
            else if(P_6[i][0]<T && P_6[i+1][0]>T){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(P_6[i][j]+(((T-P_6[i][0])/(P_6[i+1][0]-P_6[i][0]))*(P_6[i+1][j]-P_6[i][j])));
                }
                break;
            }
            else if(i==N-1){
                values.push_back(T);
                for(int j=1; j<n; j++){
                    values.push_back(-1);
                }
                break;
            }
        }
    }
}
void interpolate_T(double P, double enthalpy, vector<double>&val, vector<vector<double>>P_1, vector<vector<double>>P_4, vector<vector<double>>P_6){
    if(P==0.1){
        for(int i=0; i<N; i++){
            if(P_1[i][n-1]==enthalpy){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(P_1[i][j]);
                }
                break;
            }
            else if(i!=N-1 && P_1[i][n-1]<enthalpy && P_1[i+1][n-1]>enthalpy){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(P_1[i][j]+(((enthalpy-P_1[i][n-1])/(P_1[i+1][n-1]-P_1[i][n-1]))*(P_1[i+1][j]-P_1[i][j])));
                }
                break;
            }
            else if(i==N-1){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(-1);
                }
                break;
            }
        }      
    }
    else if(P==1.4){
        for(int i=0; i<N; i++){
            if(P_4[i][n-1]==enthalpy){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(P_4[i][j]);
                }
                break;
            }
            else if(i!=N-1 && P_4[i][n-1]<enthalpy && P_4[i+1][n-1]>enthalpy){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(P_4[i][j]+(((enthalpy-P_4[i][n-1])/(P_4[i+1][n-1]-P_4[i][n-1]))*(P_4[i+1][j]-P_4[i][j])));
                }
                break;
            }
            else if(i==N-1){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(-1);
                }
                break;
            }
        }        
    }
    else if(P==1.6){
        for(int i=0; i<N; i++){
            if(P_6[i][n-1]==enthalpy){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(P_6[i][j]);
                }
                break;
            }
            else if(i!=N-1 && P_6[i][n-1]<enthalpy && P_6[i+1][n-1]>enthalpy){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(P_6[i][j]+(((enthalpy-P_6[i][n-1])/(P_6[i+1][n-1]-P_6[i][n-1]))*(P_6[i+1][j]-P_6[i][j])));
                }
                break;
            }
            else if(i==N-1){
                val.push_back(enthalpy);
                for(int j=n-2; j>=0; j--){
                    val.push_back(-1);
                }
                break;
            }
        }
    }
    reverse(val.begin(),val.end());
}
double trapezoidal_(double P, double l_limit, double u_limit, double a, double x, vector<vector<double>>P_1, vector<vector<double>>P_4, vector<vector<double>>P_6){
    double delta_x=(u_limit-l_limit)/a;
    double ans,temp;
    vector<double> arr_l;
    vector<double> arr_u;
    interpolate_H(P,l_limit,x,arr_l, P_1, P_4, P_6);
    interpolate_H(P,u_limit,x,arr_u, P_1, P_4, P_6);
    ans=arr_u[5]+arr_l[5];
    for(int i=1; i<a; i++){
        temp=l_limit+(i*delta_x);
        vector<double> temp_v;
        interpolate_H(P,temp,x,temp_v, P_1, P_4, P_6);
        ans+=2*temp_v[5];
    }
    ans*=delta_x/2;
    return ans;
}
string Phase(double P, double T){
    string phase;
    if(T==-1){
        return "Phase cannot be found";
    }
    if(P==0.1){
        if(T<272.64){
            phase="subcooled liquid";
        }
        else if(T>272.64){
            phase="superheated vapor";
        }
        else if(T==272.64){
            phase="liquid-vapor coexistence";
        }
    }
    if(P==1.4){
        if(T<368.76){
            phase="subcooled liquid";
        }
        else if(T>368.76){
            phase="superheated vapor";
        }
        else if(T==368.76){
            phase="liquid-vapor coexistence";
        }
    }
    if(P==1.6){
        if(T<375.611){
            phase="subcooled liquid";
        }
        else if(T>375.611){
            phase="superheated vapor";
        }
        else if(T==375.611){
            phase="liquid-vapor coexistence";
        }
    }
    return phase;
}
void Enthalpy(double P, double T, double x, vector<vector<double>>&P_1, vector<vector<double>>&P_4, vector<vector<double>>&P_6, double sat1_data[2][3], double sat4_data[2][3], double sat6_data[2][3]){
    if(P==0.1){
        for(int i=0; i<N; i++){
            double ans=trapezoidal_(P,272.64,P_1[i][0],100,x,P_1,P_4,P_6);
            string phase=Phase(P,P_1[i][0]);
            if(phase=="subcooled liquid"){
                P_1[i][n-1]=(ans+sat1_data[0][1]);
            }
            else if(phase=="superheated vapor"){
                P_1[i][n-1]=(ans+sat1_data[1][1]);
            }
            else if(phase=="liquid-vapor coexistence"){
                double b=(1-x)*sat1_data[0][1]+x*sat1_data[1][1];
                P_1[i][n-1]=(ans+b);
            }
        }
    }
    else if(P==1.4){
        for(int i=0; i<N; i++){
            double ans=trapezoidal_(P,368.76,P_4[i][0],100,x,P_1,P_4,P_6);
            string phase=Phase(P,P_4[i][0]);
            if(phase=="subcooled liquid"){
                P_4[i][n-1]=(ans+sat4_data[0][1]);
            }
            else if(phase=="superheated vapor"){
                P_4[i][n-1]=(ans+sat4_data[1][1]);
            }
            else if(phase=="liquid-vapor coexistence"){
                double b=(1-x)*sat4_data[0][1]+x*sat4_data[1][1];
                P_4[i][n-1]=(ans+b);
            }
        }        
    }
    else if(P==1.6){
        for(int i=0; i<N; i++){
            double ans=trapezoidal_(P,375.61,P_6[i][0],100,x,P_1,P_4,P_6);
            string phase=Phase(P,P_6[i][0]);
            if(phase=="subcooled liquid"){
                P_6[i][n-1]=(ans+sat6_data[0][1]);
            }
            else if(phase=="superheated vapor"){
                P_6[i][n-1]=(ans+sat6_data[1][1]);
            }
            else if(phase=="liquid-vapor coexistence"){
                double b=(1-x)*sat6_data[0][1]+x*sat6_data[1][1];
                P_6[i][n-1]=(ans+b);
            }
        }        
    }
    return;
}
double Joule_Thomson(double P1, double T1, double x, vector<vector<double>>P_1, vector<vector<double>>P_4, vector<vector<double>>P_6){
    double coefficient;
    vector<double> values;
    interpolate_H(P1,T1,x,values,P_1,P_4,P_6);
    coefficient=-(1/(values[5]))*((1/values[1])-((T1/(values[1]*values[2]))*(values[3]/values[4])));
    return coefficient*1000;  
//here the joule thomson coefficient is expressed in K/MPa.  
}
double T2_(double P2, double enthalpy, vector<vector<double>>P_1, vector<vector<double>>P_4, vector<vector<double>>P_6){
    vector<double> val;
    interpolate_T(P2,enthalpy,val,P_1,P_4,P_6);
    double ans;
    if(P2==0.1){
        if(val[n-1]<16770.10 || val[n-1]>39202.70){
            ans=val[0];
        }
        else{
            ans=272.64;
        }
    }
    if(P2==1.4){
        if(val[n-1]<31450.90 || val[n-1]>46891.00){
            ans=val[0];
        }
        else{
            ans=368.76;
        }
    }
    if(P2==1.6){
        if(val[n-1]<32665.20 || val[n-1]>47338.30){
            ans=val[0];
        }
        else{
            ans=375.61;
        }
    }    
    return ans;
}
//for calculating the value of T2 first we will create a 2D vector with values of T,P and H with H calculated 
// using the above created enthalpy funcion and then use the interpolation to get the value of temperature T2
double Quality(double P1, double T1, double P2, double T2, double enthalpy, double x, vector<vector<double>>P_1, vector<vector<double>>P_4, vector<vector<double>>P_6, double sat1_data[2][3], double sat4_data[2][3], double sat6_data[2][3]){
    vector<double> val;
    double x2;
    if(T2==-1){
        cout<<"T2 Out of Range, Quality cannot be found"<<endl;
        return -1;
    }
    else{
        string phase=Phase(P2,T2);
        if(phase=="subcooled liquid"){
            x2=0;
        }
        else if(phase=="superheated vapor"){
            x2=1;
        }
        else if(phase=="liquid-vapor coexistence"){
            if(P2==0.1){
                x2=(enthalpy-sat1_data[0][1])/(sat1_data[1][1]-sat1_data[0][1]);
            }
            else if(P2==1.4){
                x2=(enthalpy-sat4_data[0][1])/(sat4_data[1][1]-sat4_data[0][1]);
            }
            else if(P2==1.6){
                x2=(enthalpy-sat6_data[0][1])/(sat6_data[1][1]-sat6_data[0][1]);
            }
        }   
    }     
    return x2;
}
double exit_temp_approx(double P1, double P2, double T1, double x, vector<vector<double>>P_1, vector<vector<double>>P_4, vector<vector<double>>P_6){
    double J=Joule_Thomson(P1,T1,x,P_1,P_4,P_6);
    double T2=T1+J*(P2-P1);
    return T2;
}
int main(){
    double P1;
    double P2;
    double T1;
    double T2;
    double x;
    cin>>P1>>P2>>T1;
    vector<vector<double>>P_1={{200, 11.590, 673.920, 1.34452, 1.41021, 118.87, 0},
                                {210, 11.430, 664.350, 1.25705, 1.30680, 120.28, 0},
                                {220, 11.260, 654.670, 1.17502, 1.20796, 121.98, 0},
                                {230, 11.090, 644.880, 1.09782, 1.11337, 123.94, 0},
                                {240, 10.920, 634.940, 1.02495, 1.02277, 126.13, 0},
                                {250, 10.750, 624.830, 0.95595, 0.93593, 128.54, 0},
                                {260, 10.570, 614.510, 0.89042, 0.85268, 131.15, 0},
                                {270, 10.390, 603.930, 0.82801, 0.77288, 133.95, 0},
                                {272.64, 10.340, 601.090, 0.81202, 0.75238, 134.73, 0},
                                {272.64, 0.047, 2.709, 0.00040, 0.03590, 94.82, 0},
                                {280, 0.045, 2.629, 0.00039, 0.03714, 96.22, 0},
                                {290, 0.044, 2.529, 0.00037, 0.03879, 98.31, 0},
                                {300, 0.042, 2.436, 0.00036, 0.04040, 100.54, 0},
                                {310, 0.040, 2.351, 0.00034, 0.04199, 102.86, 0},
                                {320, 0.039, 2.272, 0.00033, 0.04356, 105.25, 0},
                                {330, 0.038, 2.199, 0.00032, 0.04511, 107.68, 0},
                                {340, 0.037, 2.130, 0.00031, 0.04666, 110.13, 0},
                                {350, 0.036, 2.066, 0.00030, 0.04819, 112.61, 0},
                                {360, 0.035, 2.005, 0.00029, 0.04971, 115.10, 0},
                                {370, 0.034, 1.949, 0.00028, 0.05122, 117.59, 0},
                                {380, 0.033, 1.895, 0.00027, 0.05273, 120.09, 0},
                                {390, 0.032, 1.845, 0.00027, 0.05423, 122.57, 0},
                                {400, 0.031, 1.797, 0.00026, 0.05573, 125.04, 0}};

    vector<vector<double>>P_4={{200, 11.610, 674.840, 1.35051, 1.42670, 118.76, 0},
                                {210, 11.450, 665.330, 1.26327, 1.32369, 120.15, 0},
                                {220, 11.280, 655.740, 1.18149, 1.22527, 121.83, 0},
                                {230, 11.110, 646.040, 1.10455, 1.13112, 123.75, 0},
                                {240, 10.950, 636.200, 1.03196, 1.04097, 125.91, 0},
                                {250, 10.770, 626.200, 0.96327, 0.95461, 128.28, 0},
                                {260, 10.600, 616.010, 0.89808, 0.87186, 130.84, 0},
                                {270, 10.420, 605.590, 0.83605, 0.79259, 133.59, 0},
                                {280, 10.230, 594.900, 0.77686, 0.71667, 136.52, 0},
                                {290, 10.050, 583.890, 0.72023, 0.64400, 139.63, 0},
                                {300, 9.850, 572.510, 0.66589, 0.57449, 142.95, 0},
                                {310, 9.646, 560.680, 0.61360, 0.50806, 146.49, 0},
                                {320, 9.434, 548.320, 0.56311, 0.44462, 150.29, 0},
                                {330, 9.210, 535.310, 0.51417, 0.38410, 154.41, 0},
                                {340, 8.972, 521.490, 0.46650, 0.32639, 158.95, 0},
                                {350, 8.716, 506.640, 0.41978, 0.27138, 164.06, 0},
                                {360, 8.437, 490.410, 0.37359, 0.21888, 170.09, 0},
                                {368.76, 8.166, 474.640, 0.33306, 0.17477, 176.63, 0},
                                {368.76, 0.614, 35.708, 0.00716, 0.02611, 150.15, 0},
                                {370, 0.609, 35.375, 0.00703, 0.02670, 148.90, 0},
                                {380, 0.569, 33.078, 0.00624, 0.03087, 142.82, 0},
                                {390, 0.538, 31.255, 0.00569, 0.03441, 140.36, 0},
                                {400, 0.512, 29.735, 0.00527, 0.03758, 139.56, 0}};    

    vector<vector<double>>P_6={{200, 11.610, 674.980, 1.35143, 1.42923, 118.74, 0},
                                {210, 11.450, 665.480, 1.26423, 1.32628, 120.13, 0},
                                {220, 11.280, 655.910, 1.18248, 1.22793, 121.80, 0},
                                {230, 11.120, 646.220, 1.10558, 1.13384, 123.73, 0},
                                {240, 10.950, 636.400, 1.03303, 1.04376, 125.88, 0},
                                {250, 10.780, 626.410, 0.96438, 0.95747, 128.24, 0},
                                {260, 10.600, 616.240, 0.89925, 0.87480, 130.80, 0},
                                {270, 10.420, 605.840, 0.83727, 0.79561, 133.53, 0},
                                {280, 10.240, 595.180, 0.77815, 0.71977, 136.45, 0},
                                {290, 10.050, 584.200, 0.72159, 0.64719, 139.55, 0},
                                {300, 9.856, 572.860, 0.66734, 0.57777, 142.85, 0},
                                {310, 9.653, 561.080, 0.61514, 0.51145, 146.37, 0},
                                {320, 9.441, 548.770, 0.56476, 0.44813, 150.14, 0},
                                {330, 9.219, 535.830, 0.51596, 0.38773, 154.21, 0},
                                {340, 8.982, 522.100, 0.46846, 0.33018, 158.69, 0},
                                {350, 8.729, 507.370, 0.42196, 0.27534, 163.71, 0},
                                {360, 8.453, 491.320, 0.37607, 0.22307, 169.56, 0},
                                {370, 8.145, 473.430, 0.33018, 0.17314, 176.87, 0},
                                {375.611, 7.953, 462.260, 0.30409, 0.14600, 182.10, 0},
                                {375.611, 0.715, 41.542, 0.00862, 0.02400, 159.30, 0},
                                {380, 0.690, 40.086, 0.00806, 0.02623, 153.78, 0},
                                {390, 0.644, 37.415, 0.00715, 0.03054, 147.20, 0},
                                {400, 0.608, 35.308, 0.00651, 0.03422, 144.38, 0}};

    double sat1_data[2][3]={{272.64,	16770.10,	218.49},
                            {272.64,	39202.70,	300.76}};

    double sat4_data[2][3]={{368.76,	31450.90,	263.87},
                            {368.76,	46891.00,	305.74}};

    double sat6_data[2][3]={{375.61,	32665.20,	267.07},
                            {375.61,	47338.30,	306.13}};    
    
    string phase=Phase(P1,T1);
    if(phase=="subcooled liquid"){
        x=0;
    }
    else if(phase=="superheated liquid"){
        x=1;
    }
    else if(phase=="liquid-vapor coexistence"){
        cin>>x;
    }
    Enthalpy(0.1,T1,x,P_1,P_4,P_6,sat1_data,sat4_data,sat6_data);
    Enthalpy(1.4,T1,x,P_1,P_4,P_6,sat1_data,sat4_data,sat6_data);
    Enthalpy(1.6,T1,x,P_1,P_4,P_6,sat1_data,sat4_data,sat6_data);

    vector<double>values;
    interpolate_H(P1,T1, x,values, P_1, P_4, P_6);
    double enthalpy=values[n-1];
    T2=T2_(P2,enthalpy,P_1,P_4,P_6);
    double quality=Quality(P1,T1,P2,T2,enthalpy,x,P_1,P_4,P_6,sat1_data,sat4_data,sat6_data);
    double coefficient=Joule_Thomson(P1,T1,x,P_1,P_4,P_6);

    cout<<"Input Parameters:"<<endl;
    cout<<"P1: "<<P1<<"MPa, P2: "<<P2<<"MPa, T1: "<<T1<<"K"<<endl;
    cout<<"Enthalpy at P1, T1: "<<enthalpy<<" J/mol"<<endl;
    cout<<endl;    
    cout<<"1. "<<"Phase of the exit stream: "<<Phase(P2,T2)<<endl;
    cout<<"2. "<<"Temperature,T2 of the exit stream: "<<T2<<" K"<<endl;
    cout<<"   and quality of the exit stream: "<<quality<<endl;
    cout<<"3. "<<"Joule-Thomson coefficient at the inlet condition: "<<coefficient<<" K/MPa"<<endl;
    cout<<"   and approximation for the exit temperature: "<<exit_temp_approx(P1,P2,T1,x,P_1,P_4,P_6)<<" K"<<endl;
    cout<<endl; 
    return 0;
}