clear
clc

h = animatedline;
ar_uno = arduino('COM5', 'Uno', 'Libraries', 'I2C');
gy30 = device(ar_uno, 'I2CAddress', 0x23);

write(gy30, 0x11 , 'uint8');

a = 1;
while( true )
    data = read(gy30, 2,"uint8");
    lux = (double(bitshift(int16(data(1)), 4)) + data(2))/1.2;
    addpoints(h,a,lux);
    drawnow
    a = a+1;
end
