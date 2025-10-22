function [t, y] = odeRK2_22000664(odeFunc,a,b,h,y0)
% odeRK_2 solves a first order initial value ODE using second order Runge-Kuntta method
%
%
% Input variables:
% odeFunc    Name of a function file that calculates dy/dt.  
% a      The first value of t.
% b      The last value of t.
% h      Step size.
% y0     The value of the solution y at the first point (initial value).
% Output variable:
% t      A vector with the t coordinate of the solution points.
% y      A vector with the y coordinate of the solution points. 





    % Variable Initialization
    N = (b-a)/h;
    y=zeros(1,N+1);
    t=zeros(1,N+1);

    % Initial Condition
    t(1) = a;  y(1) = y0;
    

    % RK Design Parameters    
    alpha=1;
    beta=alpha;
    C1=0.5;
    C2=1-C1;

    % ODE Solver
    for i = 1:N
        t(i+1) = t(i) + h;

        % [First-point Gradient]
        K1 = odeFunc(t(i),y(i));
      
        % [Second-point Gradient]
        % calculate t2=t(i)+alpha*h
        % [TO-DO] your code goes here    
        % t2=___________________
        t2 = t(i) + alpha*h;

        % calculate y2=y(i)+ beta*K1*h
        % [TO-DO] your code goes here    
        % y2=___________________
        y2 = y(i) + beta*K1*h;

        % Calculate: K2   using t2 and y2
        % [TO-DO] your code goes here    
        % K2=___________________
        K2 = odeFunc(t2, y2);

        % Estimate: y(i+1) using RK2
        % [TO-DO] your code goes here    
        % y(i+1)=___________________
        y(i+1) = y(i) + (C1*K1 + C2*K2)*h;

        
    end

end  % END OF FUNCTION