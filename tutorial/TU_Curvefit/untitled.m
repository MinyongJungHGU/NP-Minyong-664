strain = 0:0.4:6;
stress = [0, 3, 4.5, 5.8, 5.9, 5.8, 6.2, 7.4, 9.6, 15.6, 20.7, 26.7,31.1, 35.6, 39.3, 41.5]

z1=[-0.2746; 12.8780; -10.1927; 3.1185; -0.2644];

Yhat1=polyval(flip(z1),Strain);

figure
plot(strain,stress,'*r',strain,Yhat1,'b')


T=[30, 40, 50, 60, 70, 80];
P=[1.05, 1.07, 1.09, 1.14, 1.17, 1.21];

z2=[0.0033; 0.9410];

Yhat2=polyval(z2,T);

figure
plot(T,P,'*r',T,Yhat2,'b')