%%% TEMPLATE MATLAB CODE FOR PLOTTING GRAPHS %%%%%

clc;
close all;
clear all;

freq = [0.01	0.1	0.5	1	5	8	10	13	15	18	20	25	30	50] * 1e3
v_in = [120 120 120 120 120 120 120 120 120 120 120 120 120 120] * 1e-3
v_in_distortion = [270	250	250	250	300	670	610	720	880	1000 1080 1250 1250 1330] * 1e-3
v_out = [13.0 13.0 13.0 13.0 12.0 8.4	6.4	4.0	3.0	2.2	1.7	1.1	0.7	0.2]
phase = [180.0 180.0 175.0 167.0 115.0 74.5 56.5 38.0 28.5 18.1 11.0 0.0 -1.8 -33.8]
gain = v_out./v_in
gain_db = 20*log(gain)
log_freq = log(freq)

%gain vs freq (log scale)
figure(1);
plot(log_freq,gain,'-xb'); % DATA POINTS (CROSSES) PLUS CONNECTING LINE
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Gain','Fontsize',24);
title('Open loop gain vs Frequency','Fontsize',24);
set(gca,'Fontsize',18);
grid on;

% gain (db) vs freq
figure(2);
plot(log_freq, gain_db,'-xb'); 
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Gain (db)','Fontsize',24);
title('Open Loop Gain (db) vs Frequency ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;

% open loop phase vs freq
figure(3);
plot(log_freq, phase,'-xb'); 
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Phase','Fontsize',24);
title('Open Loop Phase vs Frequency ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;

% Vi at onset of distortion vs freq
figure(3);
plot(log_freq, v_in_distortion,'-xb');
hold on;
h1 = area(log_freq(1,1:5), v_in_distortion(1,1:5));
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Vin (V)','Fontsize',24);
title('Vin at distortion vs Frequency ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;