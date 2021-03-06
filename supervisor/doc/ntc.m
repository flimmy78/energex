clear

R25 = 100000;
B = 4250;
T = linspace(-40, 125);
T0 = 25;



R1 = exp(B ./ (273.15 + 25));
R2 = exp(B ./ (273.15 + T));
R = R25 * R2 ./ R1;

%R = R25 * exp(B*(1./T - 1/25));

%R = R0 * exp(B/25) * exp(B./T);
%a = B ./ (273+T0) ^ 2;
%b = B ./ (273+T0) ^ 3;
%c = B ./ (273+T0) ^ 4;
%R = R0 * (1 - a * (T-25) + b * (T-25).^2  - c * (T-25).^3 );


plot(T, R, "-;R(T);r");
title("NTC");
xlabel('Temperature [°C]'), ylabel('R [Ohm]');
grid on


yTable = [4256752,
3005888,
2148514,
1555020,
1137312,
839314,
625338,
469127,
355224,
272045,
209803,
162713,
127117,
100000,
79215,
63150,
50649,
40885,
33195,
27014,
22079,
18226,
15124,
12598,
10542
8852,
7463,
6321,
5374,
4585,
3925,
3376,
2913,
2520];

xTable = linspace(-40, 125, 34)
hold on

stem(xTable, yTable, "-;table(T);g");

LSB = 3065 / 1.5 * yTable ./ (100000 + yTable);