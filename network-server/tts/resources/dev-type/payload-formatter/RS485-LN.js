function decodeUplink(input) {
  var ret_meta = {};
  ret_meta.dev_type = "RS485-LN-TESTBED";
  
  var ret_data = {};
  
  if(
    input.fPort != 2
    || input.bytes[0] == 0x00
    ) return null;
  
  //decode normal uplink
  if (input.bytes[0] == 0xFF) {
    ret_data.RELAY_CH0_status = (input.bytes[1] & 1) == 1 ?"ON":  "OFF";
    ret_data.RELAY_CH1_status = (input.bytes[1] >> 1) & 1 == 1 ? "ON" : "OFF";
    ret_data.RELAY_CH2_status = (input.bytes[1] >> 2) & 1 == 1 ? "ON" : "OFF";
    ret_data.RELAY_CH3_status = (input.bytes[1] >> 3) & 1 == 1 ? "ON" : "OFF";
  }
  
  //decode RELAY control response
  else if (input.bytes[0] == 0x01) {
    if (input.bytes[3] == 0x00) {
      ret_data.RELAY_CH0_status = input.bytes[4] == 0xFF ?"ON":"OFF";
    }
    
    else if (input.bytes[3] == 0x01) {
      ret_data.RELAY_CH1_status = input.bytes[4] == 0xFF ?"ON":"OFF";
    }
    
    else if (input.bytes[3] == 0x02) {
      ret_data.RELAY_CH2_status = input.bytes[4] == 0xFF ?"ON":"OFF";
    }
    
    else if (input.bytes[3] == 0x03) {
      ret_data.RELAY_CH3_status = input.bytes[4] == 0xFF ?"ON":"OFF";
    }
    
    else return null;
  }
  
  return {
    data: {
      meta: ret_meta,
      data: ret_data
    },
    warnings: [],
    errors: []
  };
}
