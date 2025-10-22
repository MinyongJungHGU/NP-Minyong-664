function [t, y] = odeEM_22000664(odeFunc,a,b,h,y0)
% odeEM solves a first order initial value ODE using Euler Explicit MODIFIED Method
%
% Input variables:
% odeFunc   Name of a function file that calculates dy/dt.  
% a      The first value of t.
% b      The last value of t.
% h      Step size.
% yIni     The value of the solution y at the first point (initial value).
% Output variable:
% t      A vector with the t coordinate of the solution points.
% y      A vector with the y coordinate of the solution points. 


    % Variable Initialization
    N = (b-a)/h;
    y=zeros(1,N+1);
    t=zeros(1,N+1);

    % Initial Condition
    y(1) = y0;
    t(1)=a;


    % ODE SOLVER
    for i = 1:N
        t(i+1) = t(i) + h;
        K1 = odeFunc(t(i),y(i));
   
        % Estimate: yE=y(i+1) using Euler Explicit Method
        % [TO-DO] your code goes here    
        % yE=___________________
        yE = y(i) + odeFunc(t(i),y(i))*h;


        % Calculate: K2 using  t(i+1) and yE
        % [TO-DO] your code goes here    
        % K2=___________________
        K2 = odeFunc(t(i+1), yE); 

        % Estimate: y(i+1)=y(i)+(K1+K2)(h/2)
        % [TO-DO] your code goes here    
        % y(i+1)=___________________
        y(i+1) = y(i) + (K1 + K2)/2*h;

    end


end  % END OF FUNCTION