function [t, y] = odeRK4_22000664(odeFunc,a,b,h,y0)
% odeRK_4 solves a first order initial value ODE using fourth order Runge-Kuntta method
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
    C1=1/6;
    C4=1/6;
    
    C2=2/6;
    C3=2/6;
    
    alpha2=1/2;
    alpha3=1/2;
    beta21=1/2;
    beta32=1/2;
    
    alpha4=1;
    beta43=1;

    beta31=0;
    beta41=0;
    beta42=0;


    % ODE Solver
    for i = 1:N
        t(i+1) = t(i) + h;

        % [First-point Gradient]
        K1 = odeFunc(t(i),y(i));
      
        % [Second-point Gradient]
        % calculate t2=t(i)+alpha2*h
        % [TO-DO] your code goes here    
        % t2=___________________
        t2 = t(i) + alpha2*h;

        % calculate y2=y(i)+ beta21*K1*h
        % [TO-DO] your code goes here    
        % y2=___________________
        y2 = y(i) + beta21*K1*h;

        % Calculate: K2   using t2 and y2
        % [TO-DO] your code goes here    
        % K2=___________________
        K2 = odeFunc(t2, y2);

        % [Third-point Gradient]
        % calculate t3=t(i)+alpha3*h
        % [TO-DO] your code goes here    
        % t3=___________________
        t3 = t(i) + alpha3*h;

        % calculate y3=y(i)+ beta31*K1*h+ beta32*K2*h
        % [TO-DO] your code goes here    
        % y3=___________________
        y3 = y(i)+ beta31*K1*h+ beta32*K2*h;

        % Calculate: K3   using t3 and y3
        % [TO-DO] your code goes here    
        % K3=___________________
        K3 = odeFunc(t3, y3);


        % [Fourth-point Gradient]
        % calculate t4=t(i)+alpha4*h
        % [TO-DO] your code goes here    
        % t4=___________________
        t4 = t(i) + alpha4*h;

        % calculate y4=y(i)+ beta41*K1*h+ beta42*K2*h+ beta43*K3*h
        % [TO-DO] your code goes here    
        % y4=___________________
        y4 = y(i)+ beta41*K1*h+ beta42*K2*h+ beta43*K3*h;

        % Calculate: K3   using t3 and y3
        % [TO-DO] your code goes here    
        % K3=___________________
        K4 = odeFunc(t4, y4);


        % Estimate: y(i+1) using RK2
        % [TO-DO] your code goes here    
        % y(i+1)=___________________
        y(i+1) = y(i) + (C1*K1 + C2*K2 + C3*K3 + C4*K4)*h;

        
    end

end  % END OF FUNCTION