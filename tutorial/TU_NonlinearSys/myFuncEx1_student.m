function F=myFuncEx1_student(Z)
    % z(1)=x; % z(2)=y
    F=zeros(2,1);
    F(1) = Z(2)-0.5*(exp(Z(1)/2)+exp(-Z(1)/2)) ;
    F(2) = 9*Z(1)^2+25*Z(2)^2-225;
end