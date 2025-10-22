function E = myLoss_ex3_student(W,X,Y)

    %% Initialization
    a0=W(1);
    a1=W(2);
    m=length(X);
    E=0;

    %% Loss Function
    % [TO-DO] Gradident of Loss Function 
    % E= __________
    for i=1:m
        E=E+(Y(i)-(a1*X(i)+a0))^2;
    end
    
    E=E/m;

end



    