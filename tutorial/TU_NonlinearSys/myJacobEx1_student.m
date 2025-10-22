function J=myJacobEx1_student(Z)
    % z(1)=x; % z(2)=y
    J=zeros(2,2);

    x=Z(1);
    y=Z(2);

    % [TO-DO] Define Jacobian
    J=[-1/4*(exp(x/2)-exp(-x/2)) 1;
        18*x 50*y];     % 2x2 matrix for this exercise
    

end