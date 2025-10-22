function dE= myLossGrad_ex3_student(W,X,Y)

    %% Initialization
    a0=W(1);
    a1=W(2);
    m=length(X);
    dE=[0;0];
    
    %% Loss Function
    % [TO-DO] Gradident of Loss Function 
    % dE= __________

    for k=1:m
        r=(Y(k)-(a1*X(k)+a0));
        dE=dE+[r;X(k)*r];    
    end
    dE=-2./m.*(dE);
end

