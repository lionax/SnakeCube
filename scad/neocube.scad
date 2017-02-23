panel_s = 66; // The size of the panel

pole_w = 8; // The width of a pole

// As for M2 screws (see DIN 912)
screw_k = 2; // Height of nut
screw_d = 2; // Diameter of screw
screw_d1 = 3.8; // Diameter of nut

pad_d = 8; // Distance between screw holes
pad_o = 2; // Distance from screw holes to edge
pad_i = 3.5; // The inset of the pads
pad_w = pad_d * 4; // The size of the pad

plane_w = 2.2; // Width of the controller plane
plane_a = 35; // Angle of the controller plane

grid_x = 8; // Number of the grid

groove_width = 10;

micro_usb_w = 10;
micro_usb_h = 5;
micro_usb_l = sqrt(2)*pole_w + 5;

power_w = 10;
power_h = 5;
power_l = sqrt(2)*pole_w + 5;

module usb() {
    translate([(panel_s / -2) - sqrt(1/2*micro_usb_h/2*micro_usb_h/2) + sqrt(1/2*2.5*2.5),
             (panel_s / 2) - ( 1/4 * (panel_s - pad_w) - 1/2 * micro_usb_w ),
             (panel_s / 2) - sqrt(1/2*micro_usb_h/2*micro_usb_h/2) - sqrt(1/2*2.5*2.5)])
    rotate([45, 0, -90])
    cube( [micro_usb_w, micro_usb_h, micro_usb_l] );
}

module power() {
    translate([(panel_s / -2) + sqrt(1/2*power_h/2*power_h/2) + sqrt(1/2*2.5*2.5),
             (panel_s / -2) + micro_usb_w + ( 1/4 * (panel_s - pad_w) - 1/2 * power_w ),
             (panel_s / -2) - sqrt(1/2*power_h/2*power_h/2) + sqrt(1/2*2.5*2.5)])
    rotate([135, 0, -90])
    cube( [power_w, power_h, power_l] );
}

module prism(l, w, h) {
   polyhedron(points=[
           [0,0,h],           // 0    front top corner
           [0,0,0],[w,0,0],   // 1, 2 front left & right bottom corners
           [0,l,h],           // 3    back top corner
           [0,l,0],[w,l,0]    // 4, 5 back left & right bottom corners
   ], faces=[ // points for all faces must be ordered clockwise when looking in
           [0,2,1],    // top face
           [3,4,5],    // base face
           [0,1,4,3],  // h face
           [1,2,5,4],  // w face
           [0,3,5,2],  // hypotenuse face
   ]);
}

module triangularPrism(edge, height) {
    translate([(panel_s / -2) + ( 1/4 * (panel_s - pad_w) - 1/2 * groove_width ),
             (panel_s / -2) + 0.5,
             (panel_s / -2) - 0.5 - pole_w, ])
    rotate([0, 0, -90])
    prism(height, edge+1, edge+1);
}
  
module pole() {
  cube([pole_w, pole_w, panel_s + pole_w * 2], center=true);
}

module pad() {
  translate([0, pad_i -pole_w, pad_i -pole_w])
  difference() {
    translate([pad_w / -2, 0, 0])
    cube([pad_w,
           screw_k * 4 + pad_o,
           screw_k * 4 + pad_o]);
    
    translate([0, -pad_i + pole_w + pad_o, screw_k * 3 / 2])
    for (i = [-1:1])
    translate([i * pad_d, 0, 0]) union() {
      cylinder(h=6 * screw_k, r=screw_d / 2, center=true, $fn=36);
      cylinder(h=screw_k, r=screw_d1/2, center=true, $fn=6);
      translate([0, screw_k * 2, 0]) cube([screw_d1, screw_k * 4, screw_k], center=true);
    }
  }
}


module pads() {
  translate([0, panel_s / -2, panel_s / -2]) rotate([0, 0, 0])   pad();
  translate([0, panel_s / +2, panel_s / -2]) rotate([0, 0, 180]) pad();
  translate([0, panel_s / -2, panel_s / +2]) rotate([0, 180, 0]) pad();
  translate([0, panel_s / +2, panel_s / +2]) rotate([180, 0, 0]) pad();
}

module box() {
  translate([panel_s / -2 - pole_w + pad_i,
             panel_s / -2 - pole_w + pad_i,
             panel_s / -2 - pole_w + pad_i])
  cube([screw_k * 3,
         screw_k * 3,
         screw_k * 3],
        center=false);
}

difference() {
    union() {
        translate([(panel_s + pole_w) / +2, (panel_s + pole_w) / +2, 0]) rotate([0, 0, 90]) pole();
        translate([(panel_s + pole_w) / -2, (panel_s + pole_w) / +2, 0]) rotate([0, 0, 90]) pole();
        translate([(panel_s + pole_w) / +2, (panel_s + pole_w) / -2, 0]) rotate([0, 0, 90]) pole();
        translate([(panel_s + pole_w) / -2, (panel_s + pole_w) / -2, 0]) rotate([0, 0, 90]) pole();

        translate([(panel_s + pole_w) / +2, 0, (panel_s + pole_w) / +2]) rotate([90, 0, 0]) pole();
        translate([(panel_s + pole_w) / -2, 0, (panel_s + pole_w) / +2]) rotate([90, 0, 0]) pole();
        translate([(panel_s + pole_w) / +2, 0, (panel_s + pole_w) / -2]) rotate([90, 0, 0]) pole();
        translate([(panel_s + pole_w) / -2, 0, (panel_s + pole_w) / -2]) rotate([90, 0, 0]) pole();

        translate([0, (panel_s + pole_w) / +2, (panel_s + pole_w) / +2]) rotate([0, 90, 0]) pole();
        translate([0, (panel_s + pole_w) / -2, (panel_s + pole_w) / +2]) rotate([0, 90, 0]) pole();
        translate([0, (panel_s + pole_w) / +2, (panel_s + pole_w) / -2]) rotate([0, 90, 0]) pole();
        translate([0, (panel_s + pole_w) / -2, (panel_s + pole_w) / -2]) rotate([0, 90, 0]) pole();

        rotate([ 0,  0,  0]) box();
        rotate([ 0,  0, 90]) box();
        rotate([ 0, 90,  0]) box();
        rotate([ 0, 90, 90]) box();
        rotate([90,  0,  0]) box();
        rotate([90,  0, -90]) box();
        rotate([90, 90,  0]) box();
        rotate([90, 90, -90]) box();

        rotate([90, 0, 0])
        intersection() {
          for (i = [0, 1])
          mirror([0, 0, i])
          translate([0, 0, panel_s / -2])
          rotate([0, 0, plane_a]) 
          difference() {
            union() {
              cube([(panel_s + 4 * plane_w) / cos(plane_a) , plane_w * 3, plane_w * 2], center=true);
              cube([plane_w * 3, (panel_s + 4 * plane_w) / cos(plane_a) , plane_w * 2], center=true);
            }
            translate([0, 0, plane_w]) cube([panel_s * 2, plane_w, plane_w * 2], center=true);
          }
          
          cube(panel_s + (pole_w - pad_i) * 2, center=true);
        }

        rotate([0, 0, 0]) pads();
        rotate([0, 90, 90]) pads();
        rotate([90, 0, 90]) pads();
    }
    rotate([ 0, 180, 90]) triangularPrism(pole_w-pad_i,groove_width);
    power();
    usb();
}
