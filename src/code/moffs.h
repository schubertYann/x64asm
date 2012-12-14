#ifndef X64_SRC_CODE_MOFFS_H
#define X64_SRC_CODE_MOFFS_H

#include "src/code/operand.h"

namespace x64 {

/** A simple memory variable (memory offset) of type byte, word, or doubleword 
	  or quadword used by some variants of the MOV instruction. The actual 
		address is given by a simple offset relative to the segment base. No ModR/M 
		byte is used in the instruction. The number shown with moffs indicates its 
		size, which is determined by the address-size attribute of the instruction.
*/
class Moffs {
	public:
		inline Moffs()
				: o_{0} {
		}

		inline Moffs(Operand o)
				: o_{o} {
		}

		template <typename T>
		inline Moffs(T* t)
				: o_{(Operand) t} {
		}

		inline operator Operand() const {
			return o_;
		}

	private:
		Operand o_;
};

/** A simple memory variable (memory offset) of type byte. */
struct Moffs8 : public Moffs {
	inline Moffs8() : Moffs{} { }
	inline Moffs8(Operand o) : Moffs{o} { }

	template <typename T>
	inline Moffs8(T* t) : Moffs{t} { }
};

/** A simple memory variable (memory offset) of type word. */
struct Moffs16 : public Moffs {
	inline Moffs16() : Moffs{} { }
	inline Moffs16(Operand o) : Moffs{o} { }

	template <typename T>
	inline Moffs16(T* t) : Moffs{t} { }
};

/** A simple memory variable (memory offset) of type doubleword. */
struct Moffs32 : public Moffs {
	inline Moffs32() : Moffs{} { }
	inline Moffs32(Operand o) : Moffs{o} { }

	template <typename T>
	inline Moffs32(T* t) : Moffs{t} { }
};

/** A simple memory variable (memory offset) of type quadword. */
struct Moffs64 : public Moffs {
	inline Moffs64() : Moffs{} { }
	inline Moffs64(Operand o) : Moffs{o} { }

	template <typename T>
	inline Moffs64(T* t) : Moffs{t} { }
};

}

#endif
