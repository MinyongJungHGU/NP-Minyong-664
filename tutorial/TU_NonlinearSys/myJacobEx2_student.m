function J=myJacobEx2_student(Z)

th=Z(1);
dx=Z(2);
dy=Z(3);
x0=0; y0=100; x1=0; y1=-100;
P0x=0;
P0y=100;
P1x=0;
P1y=-100;

% [TO-DO] Define Jacobian
% J=_________;     % 3x3 matrix for this exercise
J=[- P0y*cos(th) - P0x*sin(th), 1, 0; 
    P0x*cos(th) - P0y*sin(th), 0, 1; 
    - P1y*cos(th) - P1x*sin(th), 1, 0];

end

