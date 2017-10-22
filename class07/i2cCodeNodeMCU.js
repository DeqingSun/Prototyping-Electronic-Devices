var i2c = new I2C();
i2c.setup({ scl : NodeMCU.D3, sda: NodeMCU.D4 });

// Here is how to access I2C device
i2c.writeTo(8, 97);  //address, value
i2c.writeTo(8, [1,1,1]);  //address, value
var data=i2c.readFrom(8, 1);  //address, bytes to read
console.log(data);