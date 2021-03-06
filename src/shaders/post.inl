#pragma data_seg(".shader")
const char* post =
 "#version 430\n"
 "layout(location=0)uniform int g;"
 "layout(binding=0)uniform sampler2D v;"
 "layout(location=2)uniform vec2 d;"
 "float z=2.2;"
 "vec3 t(vec3 g)"
 "{"
   "float v=.15,z=.5,n=.1,i=.2,e=.01,d=.3,y=90,t=4.5;"
   "g*=t;"
   "g=(g*(v*g+n*z)+i*e)/(g*(v*g+z)+i*d)-e/d;"
   "float m=(y*(v*y+n*z)+i*e)/(y*(v*y+z)+i*d)-e/d;"
   "g/=m;"
   "return g;"
 "}"
 "const int i=8;"
 "vec3 t(sampler2D v,vec2 z)"
 "{"
   "vec2 g=1-2*z;"
   "vec3 d=vec3(0);"
   "float e=1,y=1,n=1,t=1/float(i);"
   "for(int f=0;f<i;++f)"
     "d.x+=t*texture(v,.5-.5*(g*e)).x,d.y+=t*texture(v,.5-.5*(g*y)).y,d.z+=t*texture(v,.5-.5*(g*n)).z,n*=.9995,y*=.9997,e*=.99988;"
   "return d;"
 "}"
 "vec3 e(vec2 z)"
 "{"
   "vec3 i=t(v,z/d.xy)/float(g);"
   "vec2 y=(z/d.xy-.5)*(d.x/d.y)*2;"
   "i.xyz*=1/pow(.09*dot(y,y)+1,2);"
   "i.xyz=t(i.xyz);"
   "i.xyz=smoothstep(vec3(0),vec3(1),i.xyz);"
   "return i.xyz;"
 "}"
 "void main()"
 "{"
   "vec3 g=e(gl_FragCoord.xy+vec2(0,0)),v=vec3(0);"
   "v+=-1*e(gl_FragCoord.xy+vec2(0,-1));"
   "v+=-1*e(gl_FragCoord.xy+vec2(-1,0));"
   "v+=5*g;"
   "v+=-1*e(gl_FragCoord.xy+vec2(1,0));"
   "v+=-1*e(gl_FragCoord.xy+vec2(0,1));"
   "v=mix(g,v,.12);"
   "gl_FragColor.xyz=pow(pow(v,vec3(1.005,1,.99)),vec3(1/z));"
 "}";
