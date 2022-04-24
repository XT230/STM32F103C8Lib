#ifndef _FONT_H_
#define _FONT_H_

static const unsigned char bits[][16]=
{
//U+0020( )
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+0021(!)
0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+0022(")
0x00,0x00,0x10,0x00,0x0C,0x00,0x02,0x00,0x10,0x00,0x0C,0x00,0x02,0x00,0x00,0x00,

//U+0023(#)
0x00,0x00,0x40,0x04,0xC0,0x3F,0x78,0x04,0x40,0x04,0xC0,0x3F,0x78,0x04,0x00,0x00,

//U+0024($)
0x00,0x00,0x70,0x18,0x88,0x20,0x88,0x20,0xFC,0xFF,0x08,0x21,0x30,0x1E,0x00,0x00,

//U+0025(%)
0xF0,0x00,0x08,0x31,0xF0,0x0C,0x80,0x03,0x60,0x1E,0x18,0x21,0x00,0x1E,0x00,0x00,

//U+0026(&)
0x00,0x1E,0xF0,0x21,0x08,0x23,0x88,0x2C,0x70,0x19,0x00,0x27,0x00,0x21,0x00,0x10,

//U+0027(')
0x00,0x00,0x12,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+0028(()
0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x18,0x18,0x04,0x20,0x02,0x40,0x00,0x00,

//U+0029())
0x00,0x00,0x02,0x40,0x04,0x20,0x18,0x18,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,

//U+002A(*)
0x40,0x02,0x40,0x02,0x80,0x01,0xF0,0x0F,0x80,0x01,0x40,0x02,0x40,0x02,0x00,0x00,

//U+002B(+)
0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0xE0,0x0F,0x00,0x01,0x00,0x01,0x00,0x01,

//U+002C(,)
0x00,0x00,0x00,0x90,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+002D(-)
0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x00,

//U+002E(.)
0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+002F(/)
0x00,0x00,0x00,0x60,0x00,0x18,0x00,0x07,0xC0,0x00,0x38,0x00,0x04,0x00,0x00,0x00,

//U+0030(0)
0x00,0x00,0xE0,0x0F,0x10,0x10,0x08,0x20,0x08,0x20,0x10,0x10,0xE0,0x0F,0x00,0x00,

//U+0031(1)
0x00,0x00,0x00,0x00,0x10,0x20,0x10,0x20,0xF8,0x3F,0x00,0x20,0x00,0x20,0x00,0x00,

//U+0032(2)
0x00,0x00,0x70,0x30,0x08,0x28,0x08,0x24,0x08,0x22,0x08,0x21,0xF0,0x30,0x00,0x00,

//U+0033(3)
0x00,0x00,0x30,0x18,0x08,0x20,0x08,0x21,0x08,0x21,0x88,0x22,0x70,0x1C,0x00,0x00,

//U+0034(4)
0x00,0x00,0x00,0x06,0x80,0x05,0x40,0x24,0x30,0x24,0xF8,0x3F,0x00,0x24,0x00,0x24,

//U+0035(5)
0x00,0x00,0xF8,0x19,0x88,0x20,0x88,0x20,0x88,0x20,0x08,0x11,0x08,0x0E,0x00,0x00,

//U+0036(6)
0x00,0x00,0xE0,0x0F,0x10,0x11,0x88,0x20,0x88,0x20,0x90,0x20,0x00,0x1F,0x00,0x00,

//U+0037(7)
0x00,0x00,0x18,0x00,0x08,0x00,0x08,0x3E,0x88,0x01,0x68,0x00,0x18,0x00,0x00,0x00,

//U+0038(8)
0x00,0x00,0x70,0x1C,0x88,0x22,0x08,0x21,0x08,0x21,0x88,0x22,0x70,0x1C,0x00,0x00,

//U+0039(9)
0x00,0x00,0xF0,0x01,0x08,0x12,0x08,0x22,0x08,0x22,0x10,0x11,0xE0,0x0F,0x00,0x00,

//U+003A(:)
0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00,0x00,0x00,

//U+003B(;)
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+003C(<)
0x00,0x00,0x00,0x01,0x80,0x02,0x40,0x04,0x20,0x08,0x10,0x10,0x08,0x20,0x00,0x00,

//U+003D(=)
0x00,0x00,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x00,0x00,

//U+003E(>)
0x00,0x00,0x08,0x20,0x10,0x10,0x20,0x08,0x40,0x04,0x80,0x02,0x00,0x01,0x00,0x00,

//U+003F(?)
0x00,0x00,0x70,0x00,0x48,0x00,0x08,0x30,0x08,0x37,0x88,0x00,0x70,0x00,0x00,0x00,

//U+0040(@)
0xC0,0x07,0x30,0x18,0xC8,0x27,0x28,0x28,0xE8,0x2F,0x10,0x28,0xE0,0x17,0x00,0x00,

//U+0041(A)
0x00,0x20,0x00,0x3C,0xC0,0x23,0x38,0x02,0xE0,0x02,0x00,0x27,0x00,0x38,0x00,0x20,

//U+0042(B)
0x08,0x20,0xF8,0x3F,0x88,0x20,0x88,0x20,0x88,0x20,0x70,0x11,0x00,0x0E,0x00,0x00,

//U+0043(C)
0xC0,0x07,0x30,0x18,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x10,0x38,0x08,0x00,0x00,

//U+0044(D)
0x08,0x20,0xF8,0x3F,0x08,0x20,0x08,0x20,0x08,0x20,0x10,0x10,0xE0,0x0F,0x00,0x00,

//U+0045(E)
0x08,0x20,0xF8,0x3F,0x88,0x20,0x88,0x20,0xE8,0x23,0x08,0x20,0x10,0x18,0x00,0x00,

//U+0046(F)
0x08,0x20,0xF8,0x3F,0x88,0x20,0x88,0x00,0xE8,0x03,0x08,0x00,0x10,0x00,0x00,0x00,

//U+0047(G)
0xC0,0x07,0x30,0x18,0x08,0x20,0x08,0x20,0x08,0x22,0x38,0x1E,0x00,0x02,0x00,0x00,

//U+0048(H)
0x08,0x20,0xF8,0x3F,0x08,0x21,0x00,0x01,0x00,0x01,0x08,0x21,0xF8,0x3F,0x08,0x20,

//U+0049(I)
0x00,0x00,0x08,0x20,0x08,0x20,0xF8,0x3F,0x08,0x20,0x08,0x20,0x00,0x00,0x00,0x00,

//U+004A(J)
0x00,0xC0,0x00,0x80,0x08,0x80,0x08,0x80,0xF8,0x7F,0x08,0x00,0x08,0x00,0x00,0x00,

//U+004B(K)
0x08,0x20,0xF8,0x3F,0x88,0x20,0xC0,0x01,0x28,0x26,0x18,0x38,0x08,0x20,0x00,0x00,

//U+004C(L)
0x08,0x20,0xF8,0x3F,0x08,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x30,0x00,0x00,

//U+004D(M)
0x08,0x20,0xF8,0x3F,0xF8,0x01,0x00,0x3E,0xF8,0x01,0xF8,0x3F,0x08,0x20,0x00,0x00,

//U+004E(N)
0x08,0x20,0xF8,0x3F,0x30,0x20,0xC0,0x00,0x00,0x07,0x08,0x18,0xF8,0x3F,0x08,0x00,

//U+004F(O)
0xE0,0x0F,0x10,0x10,0x08,0x20,0x08,0x20,0x08,0x20,0x10,0x10,0xE0,0x0F,0x00,0x00,

//U+0050(P)
0x08,0x20,0xF8,0x3F,0x08,0x21,0x08,0x01,0x08,0x01,0x08,0x01,0xF0,0x00,0x00,0x00,

//U+0051(Q)
0xE0,0x0F,0x10,0x10,0x08,0x28,0x08,0x28,0x08,0x30,0x10,0x50,0xE0,0x4F,0x00,0x00,

//U+0052(R)
0x08,0x20,0xF8,0x3F,0x88,0x20,0x88,0x00,0x88,0x03,0x88,0x0C,0x70,0x30,0x00,0x20,

//U+0053(S)
0x00,0x00,0x70,0x38,0x88,0x20,0x08,0x21,0x08,0x21,0x08,0x22,0x38,0x1C,0x00,0x00,

//U+0054(T)
0x18,0x00,0x08,0x00,0x08,0x20,0xF8,0x3F,0x08,0x20,0x08,0x00,0x18,0x00,0x00,0x00,

//U+0055(U)
0x08,0x00,0xF8,0x1F,0x08,0x20,0x00,0x20,0x00,0x20,0x08,0x20,0xF8,0x1F,0x08,0x00,

//U+0056(V)
0x08,0x00,0x78,0x00,0x88,0x07,0x00,0x38,0x00,0x0E,0xC8,0x01,0x38,0x00,0x08,0x00,

//U+0057(W)
0x08,0x00,0xF8,0x03,0x00,0x3E,0xF8,0x01,0x00,0x3E,0xF8,0x03,0x08,0x00,0x00,0x00,

//U+0058(X)
0x08,0x20,0x18,0x30,0x68,0x2C,0x80,0x03,0x80,0x03,0x68,0x2C,0x18,0x30,0x08,0x20,

//U+0059(Y)
0x08,0x00,0x38,0x00,0xC8,0x20,0x00,0x3F,0xC8,0x20,0x38,0x00,0x08,0x00,0x00,0x00,

//U+005A(Z)
0x10,0x20,0x08,0x38,0x08,0x26,0x08,0x21,0xC8,0x20,0x38,0x20,0x08,0x18,0x00,0x00,

//U+005B([)
0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x7F,0x02,0x40,0x02,0x40,0x02,0x40,0x00,0x00,

//U+005C(\)
0x00,0x00,0x04,0x00,0x38,0x00,0xC0,0x01,0x00,0x06,0x00,0x38,0x00,0xC0,0x00,0x00,

//U+005D(])
0x00,0x00,0x02,0x40,0x02,0x40,0x02,0x40,0xFE,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,

//U+005E(^)
0x00,0x00,0x00,0x00,0x04,0x00,0x02,0x00,0x02,0x00,0x04,0x00,0x00,0x00,0x00,0x00,

//U+005F(_)
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,

//U+0060(`)
0x00,0x00,0x02,0x00,0x02,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+0061(a)
0x00,0x00,0x00,0x19,0x80,0x24,0x80,0x24,0x80,0x12,0x00,0x3F,0x00,0x20,0x00,0x00,

//U+0062(b)
0x10,0x00,0xF0,0x3F,0x00,0x11,0x80,0x20,0x80,0x20,0x00,0x11,0x00,0x0E,0x00,0x00,

//U+0063(c)
0x00,0x00,0x00,0x0E,0x00,0x11,0x80,0x20,0x80,0x20,0x80,0x20,0x00,0x11,0x00,0x00,

//U+0064(d)
0x00,0x00,0x00,0x1F,0x80,0x20,0x80,0x20,0x80,0x20,0x90,0x10,0xF0,0x3F,0x00,0x20,

//U+0065(e)
0x00,0x00,0x00,0x1F,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x00,0x17,0x00,0x00,

//U+0066(f)
0x00,0x00,0x80,0x20,0x80,0x20,0xE0,0x3F,0x90,0x20,0x90,0x20,0x20,0x00,0x00,0x00,

//U+0067(g)
0x00,0x00,0x00,0x6B,0x80,0x94,0x80,0x94,0x80,0x94,0x80,0x93,0x80,0x60,0x00,0x00,

//U+0068(h)
0x10,0x20,0xF0,0x3F,0x00,0x21,0x80,0x00,0x80,0x00,0x80,0x20,0x00,0x3F,0x00,0x20,

//U+0069(i)
0x00,0x00,0x80,0x20,0x98,0x20,0x98,0x3F,0x00,0x20,0x00,0x20,0x00,0x00,0x00,0x00,

//U+006A(j)
0x00,0x00,0x00,0xC0,0x00,0x80,0x80,0x80,0x98,0x80,0x98,0x7F,0x00,0x00,0x00,0x00,

//U+006B(k)
0x10,0x20,0xF0,0x3F,0x00,0x24,0x00,0x06,0x80,0x29,0x80,0x30,0x80,0x20,0x00,0x00,

//U+006C(l)
0x00,0x00,0x10,0x20,0x10,0x20,0xF8,0x3F,0x00,0x20,0x00,0x20,0x00,0x00,0x00,0x00,

//U+006D(m)
0x80,0x20,0x80,0x3F,0x80,0x20,0x80,0x00,0x80,0x3F,0x80,0x20,0x80,0x00,0x00,0x3F,

//U+006E(n)
0x80,0x20,0x80,0x3F,0x00,0x21,0x80,0x00,0x80,0x00,0x80,0x20,0x00,0x3F,0x00,0x20,

//U+006F(o)
0x00,0x00,0x00,0x1F,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x00,0x1F,0x00,0x00,

//U+0070(p)
0x80,0x80,0x80,0xFF,0x00,0x91,0x80,0x20,0x80,0x20,0x00,0x11,0x00,0x0E,0x00,0x00,

//U+0071(q)
0x00,0x00,0x00,0x0E,0x00,0x11,0x80,0x20,0x80,0x20,0x00,0x91,0x80,0xFF,0x00,0x80,

//U+0072(r)
0x80,0x20,0x80,0x20,0x80,0x3F,0x00,0x21,0x80,0x20,0x80,0x00,0x80,0x01,0x00,0x00,

//U+0073(s)
0x00,0x00,0x00,0x33,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x19,0x00,0x00,

//U+0074(t)
0x00,0x00,0x80,0x00,0x80,0x00,0xE0,0x1F,0x80,0x20,0x80,0x20,0x00,0x10,0x00,0x00,

//U+0075(u)
0x80,0x00,0x80,0x1F,0x00,0x20,0x00,0x20,0x00,0x20,0x80,0x10,0x80,0x3F,0x00,0x20,

//U+0076(v)
0x80,0x00,0x80,0x03,0x80,0x0C,0x00,0x30,0x80,0x0C,0x80,0x03,0x80,0x00,0x00,0x00,

//U+0077(w)
0x80,0x01,0x80,0x0E,0x00,0x30,0x80,0x0C,0x80,0x07,0x00,0x38,0x80,0x06,0x80,0x01,

//U+0078(x)
0x00,0x00,0x80,0x20,0x80,0x31,0x80,0x0E,0x00,0x2E,0x80,0x31,0x80,0x20,0x00,0x00,

//U+0079(y)
0x80,0x00,0x80,0x81,0x80,0x86,0x00,0x78,0x00,0x18,0x80,0x06,0x80,0x01,0x80,0x00,

//U+007A(z)
0x00,0x00,0x80,0x21,0x80,0x30,0x80,0x2C,0x80,0x22,0x80,0x21,0x80,0x30,0x00,0x00,

//U+007B({)
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFC,0x3E,0x02,0x40,0x02,0x40,

//U+007C(|)
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,

//U+007D(})
0x02,0x40,0x02,0x40,0xFC,0x3E,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//U+007E(~)
0x00,0x00,0x02,0x00,0x01,0x00,0x02,0x00,0x02,0x00,0x04,0x00,0x02,0x00,0x00,0x00,

//U+007F()
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};

#endif