clear
clc

ar_uno = arduino('COM5', 'Uno', 'Libraries', 'I2C');
gy30 = device(ar_uno, 'I2CAddress', 0x23);

write(gy30, 0x10, 'uint8');

% From I2C Temp Sensor Example
%data = read(gy30, 2,"uint8");
%lux = (double(bitshift(int16(data(1)), 4)) + data(2))/1.2

a = 10;
while( a<20 )
    data = read(gy30, 2,"uint8");
    lux = (double(bitshift(int16(data(1)), 4)) + data(2))/1.2
    a = a+1;
end


