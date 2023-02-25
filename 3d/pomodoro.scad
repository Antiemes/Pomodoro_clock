module speaker()
{
  rotate([0, 90, 0]) cylinder(d=27, h=4);
}

module battery()
{
  #translate([10, 0, 0]) rotate([0, 90, 0]) cylinder(d=18.6, h=65);
}

//battery();

difference()
{
  hull()
  {
    for(off=[[0, 10, 10], [0, -10, 10], [0, -10, -25], [0, 10, -25]])
    {
      translate(off) rotate([0, 90, 0]) cylinder(d=16, h=90);
    }
  }
  difference()
  {
    hull()
    {
      for(off=[[4, 10, 8], [4, -10, 8], [4, -10, -25], [4, 10, -25]])
      {
        translate(off) rotate([0, 90, 0]) cylinder(d=11, h=87);
      }
    }
    for (m=[0, 1])
    mirror([0, m, 0])
    for (of=[20, 60])
    translate([of, 8, 0])
    difference()
    {
      linear_extrude(height=8, center=true) polygon(points=[[0, 7], [16, 7], [12, 0], [4, 0]]);
      translate([8 - 2.5, 4.5, -6]) cube([5, 2.5, 12]);
    }
  }
  translate([0, 0, -68]) cube([200, 100, 100], center=true);
  translate([2, 0, 0]) speaker();
  for(a=[0:60:359]) rotate([a, 0, 0]) translate([-1, 10, 0]) rotate([0, 90, 0]) cylinder(d=4, h=10, $fn=30);
  for(a=[30:120:359]) rotate([a, 0, 0]) translate([-1, 4, 0]) rotate([0, 90, 0]) cylinder(d=4, h=10, $fn=30);
  for(of=[25, 45, 65])
  {
    translate([of, 0, 13])
    {
      cylinder(d=4.5, h=6, $fn=30);
      translate([0, 0, 0]) cube([6.5, 6.5, 6.5], center=true);
    }
  }
}
for (ofs=[-15.5, 15.5])
{
  translate([0, ofs, -16]) rotate([0, 90, 0]) cylinder(d=2, h=90, $fn=20);
  translate([84, ofs, 0]) cylinder(d=2, h=5, $fn=20);
}
