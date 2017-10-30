%%% TEMPLATE MATLAB CODE FOR PLOTTING GRAPHS %%%%%

clc;
close all;
clear all;

%open loop values
open_freq = [0.01	0.1	0.5	1	5	8	10	13	15	18	20	25	30	50] * 1e3;
open_v_in = [120 120 120 120 120 120 120 120 120 120 120 120 120 120] * 1e-3;
open_v_out = [13.0 13.0 13.0 13.0 12.0 8.4	6.4	4.0	3.0	2.2	1.7	1.1	0.7	0.2];
open_v_in_distortion = [270	250	250	250	300	670	610	720	880	1000 1080 1250 1250 1330] * 1e-3;
open_phase = [180.0 180.0 175.0 167.0 115.0 74.5 56.5 38.0 28.5 18.1 11.0 0.0 -1.8 -33.8];

open_v_out_current_limit = [16.2 16.2 16.2 16.2 16.0 16.0 15.8 13.4 9.0	4.6];
open_rl = [1000	900	800	700	600	500	400	300	200	100];

open_gain = open_v_out./open_v_in;
open_gain_db = 20*log(open_gain);
open_freq_log = log(open_freq);

%closed loop values
closed_freq = [0.01	0.1	0.5	1	5	8	10	13	15	18	20	25	30	50] * 1e3;
closed_v_in = [120 120 120 120 120 120 120 120 120 120 120 120 120 120] * 1e-3;
closed_v_out = [6.16	6.16	6.12	6.16	6.88	7.60	6.88	4.92	3.72	3.40	1.98	1.15	0.76	0.23];
closed_v_in_distortion = [510	510	510	520	470	350	390	490	570	710	940	1100	1100	1260] * 1e-3;

closed_v_out_current_limit = [7.80	7.68	7.68	7.68	7.68	7.68	7.68	7.68	7.60	4.40];
closed_rl = [1000	900	800	700	600	500	400	300	200	100];

closed_gain = closed_v_out./closed_v_in;
closed_gain_db = 20*log(closed_gain);
closed_freq_log = log(closed_freq);


%gain vs freq (log scale)
figure(1);
plot(open_freq_log,open_gain,'-xb'); 
hold on
plot(open_freq_log, closed_gain,'-or');
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Gain','Fontsize',24);
title('Gain vs Frequency','Fontsize',24);
set(gca,'Fontsize',18);
grid on;
legend('Open Loop Gain', 'Closed Loop Gain');

% gain (db) vs freq
figure(2);
plot(open_freq_log, open_gain_db,'-xb'); 
hold on
plot(open_freq_log, closed_gain_db,'-or');
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Gain (db)','Fontsize',24);
title('Gain (db) vs Frequency ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;
legend('Open Loop Gain', 'Closed Loop Gain');


% open loop phase vs freq
figure(3);
plot(open_freq_log, open_phase,'-xb'); 
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Phase','Fontsize',24);
title('Open Loop Phase vs Frequency ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;

% Vi at onset of distortion vs freq
figure(3);
subplot(2,1,1);
plot(open_freq_log, open_v_in_distortion,'-xb');
hold on;
h1 = area(open_freq_log(1,1:5), open_v_in_distortion(1,1:5));
h1.FaceColor = 'b';
h1.FaceAlpha = 0.5;
h1.EdgeAlpha = 0;
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Vin (V)','Fontsize',24);
title('Open loop Vin at distortion vs Frequency ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;
hold off;

subplot(2,1,2);
plot(open_freq_log, closed_v_in_distortion,'-or');
hold on;
h1 = area(open_freq_log(1,1:8), closed_v_in_distortion(1,1:8));
h1.FaceColor = 'r';
h1.FaceAlpha = 0.5;
h1.EdgeAlpha = 0;
xlabel('Frequency (log10)','Fontsize',24);
ylabel('Vin (V)','Fontsize',24);
title('Closed loop Vin at distortion vs Frequency ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;
hold off;


% Vout pk-pj vs 1/Rl
figure(4);
plot(open_rl, open_v_out_current_limit,'-xb');
xlabel('RL (ohm)','Fontsize',24);
ylabel('Vout (V))','Fontsize',24);
title('Vout vs RL ','Fontsize',24);
set(gca,'Fontsize',18);
grid on;

