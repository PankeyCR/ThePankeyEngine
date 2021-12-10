
#ifndef ColorRGBA_hpp
#define ColorRGBA_hpp

#include "Triangle.hpp"
#include "PrimitiveList.hpp"
#include "MonkeyFile.hpp"
#include "DefaultMonkeyFile.hpp"
#include "LinkedList.hpp"
#include "CommandReader.hpp"
#include "Vector3f.hpp"
#include "Vector4f.hpp"
#include "SD.h"

namespace ame{

class ColorRGBA : public Printable{
    public:
		float r = 0;
		float g = 0;
		float b = 0;
		float a = 1;
		const static float GAMMA;
		const static ColorRGBA* Black;
		const static ColorRGBA* White;
		const static ColorRGBA* DarkGray;
		const static ColorRGBA* Gray;
		const static ColorRGBA* LightGray;
		const static ColorRGBA* Red;
		const static ColorRGBA* Green;
		const static ColorRGBA* Blue;
		const static ColorRGBA* Yellow;
		const static ColorRGBA* Magenta;
		const static ColorRGBA* Cyan;
		const static ColorRGBA* Orange;
		const static ColorRGBA* Brown;
		const static ColorRGBA* Pink;
		const static ColorRGBA* BlackNoAlpha;
		
		// static ColorRGBA Black(){		return ColorRGBA(0.0f, 0.0f, 0.0f, 1.0f);}
		// static ColorRGBA White(){		return ColorRGBA(1.0f, 1.0f, 1.0f, 1.0f);}
		// static ColorRGBA DarkGray(){	return ColorRGBA(0.2f, 0.2f, 0.2f, 1.0f);}
		// static ColorRGBA Gray(){		return ColorRGBA(0.5f, 0.5f, 0.5f, 1.0f);}
		// static ColorRGBA LightGray(){	return ColorRGBA(0.8f, 0.8f, 0.8f, 1.0f);}
		// static ColorRGBA Red(){			return ColorRGBA(1.0f, 0.0f, 0.0f, 1.0f);}
		// static ColorRGBA Green(){		return ColorRGBA(0.0f, 1.0f, 0.0f, 1.0f);}
		// static ColorRGBA Blue(){		return ColorRGBA(0.0f, 0.0f, 1.0f, 1.0f);}
		// static ColorRGBA Yellow(){		return ColorRGBA(1.0f, 1.0f, 0.0f, 1.0f);}
		// static ColorRGBA Magenta(){		return ColorRGBA(1.0f, 0.0f, 1.0f, 1.0f);}
		// static ColorRGBA Cyan(){		return ColorRGBA(0.0f, 1.0f, 1.0f, 1.0f);}
		// static ColorRGBA Orange(){		return ColorRGBA(251.0f / 255.0f, 130.0f / 255.0f, 0.0f, 1.0f);}
		// static ColorRGBA Brown(){		return ColorRGBA(65.0f / 255.0f, 40.0f / 255.0f, 25.0f / 255.0f, 1.0f);}
		// static ColorRGBA Pink(){		return ColorRGBA(1.0f, 0.68f, 0.68f, 1.0f);}
		// static ColorRGBA BlackNoAlpha(){return ColorRGBA(0.0f, 0.0f, 0.0f, 0.0f);}
		
		ColorRGBA(){}
		ColorRGBA(float cr, float cg, float cb, float ca){
			r = cr;
			g = cg;
			b = cb;
			a = ca;
		}
		ColorRGBA(const ColorRGBA& color){
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}
		virtual ~ColorRGBA(){}
		
		size_t printTo(Print& p) const{
			p.print(r);p.print(',');
			p.print(g);p.print(',');
			p.print(b);p.print(',');
			p.print(a);
			return sizeof(r) + sizeof(g) + sizeof(b) + sizeof(a);
		}
		
		ColorRGBA& operator=(const ColorRGBA& color){
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}
		
		bool operator==(const ColorRGBA& color){
			return 	r == color.r &&
					g == color.g &&
					b == color.b &&
					a == color.a;
		}
		
		bool operator!=(const ColorRGBA& color){
			return 	r != color.r &&
					g != color.g &&
					b != color.b &&
					a != color.a;
		}
		
		ColorRGBA set(float cr, float cg, float cb, float ca) {
			r = cr;
			g = cg;
			b = cb;
			a = ca;
			return *this;
		}
		
		ColorRGBA set(const ColorRGBA& color){
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}
		
		ColorRGBA setRed(float value) {
			r = value;
			return *this;
		}
		
		ColorRGBA setGreen(float value) {
			g = value;
			return *this;
		}
		
		ColorRGBA setBlue(float value) {
			b = value;
			return *this;
		}
		
		ColorRGBA setAlpha(float value) {
			a = value;
			return *this;
		}
		
		void clamp() {
			// r = FastMath.clamp(r, 0f, 1f);
			// g = FastMath.clamp(g, 0f, 1f);
			// b = FastMath.clamp(b, 0f, 1f);
			// a = FastMath.clamp(a, 0f, 1f);
		}
		
		LinkedList<float> getColorArray() {
			LinkedList<float> list;
			list.add(r);
			list.add(g);
			list.add(b);
			list.add(a);
			return list;
		}
		
		float getAlpha() {
			return a;
		}
		
		float getRed() {
			return r;
		}
		
		float getBlue() {
			return b;
		}
		
		float getGreen() {
			return g;
		}
		
		ColorRGBA interpolateLocal(ColorRGBA finalColor, float changeAmount) {
			r = (1 - changeAmount) * r + changeAmount * finalColor.r;
			g = (1 - changeAmount) * g + changeAmount * finalColor.g;
			b = (1 - changeAmount) * b + changeAmount * finalColor.b;
			a = (1 - changeAmount) * a + changeAmount * finalColor.a;
			return *this;
		}
		
		ColorRGBA interpolateLocal(ColorRGBA beginColor, ColorRGBA finalColor, float changeAmount) {
			r = (1 - changeAmount) * beginColor.r + changeAmount * finalColor.r;
			g = (1 - changeAmount) * beginColor.g + changeAmount * finalColor.g;
			b = (1 - changeAmount) * beginColor.b + changeAmount * finalColor.b;
			a = (1 - changeAmount) * beginColor.a + changeAmount * finalColor.a;
			return *this;
		}
		
		static ColorRGBA randomColor() {
			ColorRGBA rVal = ColorRGBA(0, 0, 0, 1);
			// rVal.r = FastMath.nextRandomFloat();
			// rVal.g = FastMath.nextRandomFloat();
			// rVal.b = FastMath.nextRandomFloat();
			return rVal;
		}
		
		ColorRGBA mult(ColorRGBA c) {
			return ColorRGBA(c.r * r, c.g * g, c.b * b, c.a * a);
		}
		
		ColorRGBA mult(float scalar) {
			return ColorRGBA(scalar * r, scalar * g, scalar * b, scalar * a);
		}
		
		ColorRGBA multLocal(float scalar) {
			r *= scalar;
			g *= scalar;
			b *= scalar;
			a *= scalar;
			return *this;
		}
		
		ColorRGBA add(ColorRGBA c) {
			return ColorRGBA(c.r + r, c.g + g, c.b + b, c.a + a);
		}
		
		ColorRGBA addLocal(ColorRGBA c) {
			set(c.r + r, c.g + g, c.b + b, c.a + a);
			return *this;
		}
		
		String toString() {
			return "Color[" + String(r) + ", " + String(g) + ", " + String(b) + ", " + String(a) + "]";
		}
		
		ColorRGBA* clone() {
			return new ColorRGBA(*this);
		}
		
		LinkedList<float> toArray() {
			LinkedList<float> floats;
			floats.add(r);
			floats.add(g);
			floats.add(b);
			floats.add(a);
			return floats;
		}
		
		bool equals(cppObject* o) {
			// if (!(o instanceof ColorRGBA)) {
				// return false;
			// }

			// if (this == o) {
				// return true;
			// }

			// ColorRGBA comp = (ColorRGBA) o;
			// if (Float.compare(r, comp.r) != 0) {
				// return false;
			// }
			// if (Float.compare(g, comp.g) != 0) {
				// return false;
			// }
			// if (Float.compare(b, comp.b) != 0) {
				// return false;
			// }
			// if (Float.compare(a, comp.a) != 0) {
				// return false;
			// }
			return true;
		}
		
		// int hashCode() {
			// int hash = 37;
			// hash += 37 * hash + Float.floatToIntBits(r);
			// hash += 37 * hash + Float.floatToIntBits(g);
			// hash += 37 * hash + Float.floatToIntBits(b);
			// hash += 37 * hash + Float.floatToIntBits(a);
			// return hash;
		// }
		
		// public void write(JmeExporter e) throws IOException {
			// OutputCapsule capsule = e.getCapsule(this);
			// capsule.write(r, "r", 0);
			// capsule.write(g, "g", 0);
			// capsule.write(b, "b", 0);
			// capsule.write(a, "a", 0);
		// }
		
		// public void read(JmeImporter e) throws IOException {
			// InputCapsule capsule = e.getCapsule(this);
			// r = capsule.readFloat("r", 0);
			// g = capsule.readFloat("g", 0);
			// b = capsule.readFloat("b", 0);
			// a = capsule.readFloat("a", 0);
		// }
		
		LinkedList<byte> asBytesRGBA() {
			LinkedList<byte> store;
			store[0] = (byte) ((int) (r * 255) & 0xFF);
			store[1] = (byte) ((int) (g * 255) & 0xFF);
			store[2] = (byte) ((int) (b * 255) & 0xFF);
			store[3] = (byte) ((int) (a * 255) & 0xFF);
			return store;
		}
		
		int asIntARGB() {
			int argb = (((int) (a * 255) & 0xFF) << 24)
					| (((int) (r * 255) & 0xFF) << 16)
					| (((int) (g * 255) & 0xFF) << 8)
					| (((int) (b * 255) & 0xFF));
			return argb;
		}
		
		int asIntRGBA() {
			int rgba = (((int) (r * 255) & 0xFF) << 24)
					| (((int) (g * 255) & 0xFF) << 16)
					| (((int) (b * 255) & 0xFF) << 8)
					| (((int) (a * 255) & 0xFF));
			return rgba;
		}
		
		int asIntABGR() {
			int abgr = (((int) (a * 255) & 0xFF) << 24)
					| (((int) (b * 255) & 0xFF) << 16)
					| (((int) (g * 255) & 0xFF) << 8)
					| (((int) (r * 255) & 0xFF));
			return abgr;
		}
		
		ColorRGBA fromIntARGB(int color) {
			a = ((byte) (color >> 24) & 0xFF) / 255.0f;
			r = ((byte) (color >> 16) & 0xFF) / 255.0f;
			g = ((byte) (color >> 8) & 0xFF) / 255.0f;
			b = ((byte) (color) & 0xFF) / 255.0f;
			return *this;
		}
		
		ColorRGBA fromIntRGBA(int color) {
			r = ((byte) (color >> 24) & 0xFF) / 255.0f;
			g = ((byte) (color >> 16) & 0xFF) / 255.0f;
			b = ((byte) (color >> 8) & 0xFF) / 255.0f;
			a = ((byte) (color) & 0xFF) / 255.0f;
			return *this;
		}
		
		ColorRGBA fromIntABGR(int color) {
			a = ((byte) (color >> 24) & 0xFF) / 255.0f;
			b = ((byte) (color >> 16) & 0xFF) / 255.0f;
			g = ((byte) (color >> 8) & 0xFF) / 255.0f;
			r = ((byte) (color) & 0xFF) / 255.0f;
			return *this;
		}
		
		static ColorRGBA fromRGBA255(int r, int g, int b, int a) {
			return ColorRGBA(r / 255.0F, g / 255.0F, b / 255.0F, a / 255.0F);
		}
		
		Vector3f toVector3f() {
			return Vector3f(r, g, b);
		}
		
		Vector4f toVector4f() {
			return Vector4f(r, g, b, a);
		}
		
		ColorRGBA setAsSrgb(float cr, float cg, float cb, float ca) {
			r = (float) pow(cr, GAMMA);
			b = (float) pow(cb, GAMMA);
			g = (float) pow(cg, GAMMA);
			a = ca;

			return *this;
		}
		
		ColorRGBA getAsSrgb() {
			ColorRGBA srgb;
			float invGamma = 1.0f / GAMMA;
			srgb.r = (float) pow(r, invGamma);
			srgb.g = (float) pow(g, invGamma);
			srgb.b = (float) pow(b, invGamma);
			srgb.a = a;
			return srgb;
		}
};

const float ColorRGBA::GAMMA = 2.2f;

const ColorRGBA* ColorRGBA::Black = 		new ColorRGBA(0.0f, 0.0f, 0.0f, 1.0f);
const ColorRGBA* ColorRGBA::White = 		new ColorRGBA(1.0f, 1.0f, 1.0f, 1.0f);
const ColorRGBA* ColorRGBA::DarkGray = 		new ColorRGBA(0.2f, 0.2f, 0.2f, 1.0f);
const ColorRGBA* ColorRGBA::Gray = 			new ColorRGBA(0.5f, 0.5f, 0.5f, 1.0f);
const ColorRGBA* ColorRGBA::LightGray = 	new ColorRGBA(0.8f, 0.8f, 0.8f, 1.0f);
const ColorRGBA* ColorRGBA::Red = 			new ColorRGBA(1.0f, 0.0f, 0.0f, 1.0f);
const ColorRGBA* ColorRGBA::Green = 		new ColorRGBA(0.0f, 1.0f, 0.0f, 1.0f);
const ColorRGBA* ColorRGBA::Blue = 			new ColorRGBA(0.0f, 0.0f, 1.0f, 1.0f);
const ColorRGBA* ColorRGBA::Yellow = 		new ColorRGBA(1.0f, 1.0f, 0.0f, 1.0f);
const ColorRGBA* ColorRGBA::Magenta = 		new ColorRGBA(1.0f, 0.0f, 1.0f, 1.0f);
const ColorRGBA* ColorRGBA::Cyan = 			new ColorRGBA(0.0f, 1.0f, 1.0f, 1.0f);
const ColorRGBA* ColorRGBA::Orange = 		new ColorRGBA(251.0f / 255.0f, 130.0f / 255.0f, 0.0f, 1.0f);
const ColorRGBA* ColorRGBA::Brown = 		new ColorRGBA(65.0f / 255.0f, 40.0f / 255.0f, 25.0f / 255.0f, 1.0f);
const ColorRGBA* ColorRGBA::Pink = 			new ColorRGBA(1.0f, 0.68f, 0.68f, 1.0f);
const ColorRGBA* ColorRGBA::BlackNoAlpha = 	new ColorRGBA(0.0f, 0.0f, 0.0f, 0.0f);

}

#endif 
