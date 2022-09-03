#include "Base/Reflect.h"
#include "Include/IncludeBase.h"

namespace Reflect
{

    //--------------------------------------------------------
    // Type descriptors for std::vector
    //--------------------------------------------------------

    struct TypeVector : GType
    {
        GType *ItemType;
        size_t (*getSize)(const void *);
        const void *(*getItem)(const void *, size_t);

        template <typename ItemT>
        TypeVector(ItemT *)
            : GType{"GVector", sizeof(GVector<ItemT>)},
            ItemType{GResolver<ItemT>::get()}
        {
            getSize = [](const void *vecPtr) -> size_t
            {
                const auto &vec = *(const GVector<ItemT> *)vecPtr;
                return vec.size();
            };
            getItem = [](const void *vecPtr, size_t index) -> const void *
            {
                const auto &vec = *(const GVector<ItemT> *)vecPtr;
                return &vec[index];
            };
        }
        virtual GString getName() const override
        {
            return GString("GVector<") + ItemType->getName() + ">";
        }
        virtual void dump(const void *obj, int indentLevel) const override
        {
            size_t numItems = getSize(obj);
            std::cout << getName();
            if (numItems == 0)
            {
                std::cout << "{}";
            }
            else
            {
                std::cout << "{" << std::endl;
                for (size_t index = 0; index < numItems; index++)
                {
                    std::cout << GString(4 * (indentLevel + 1), ' ') << "[" << index << "] ";
                    ItemType->dump(getItem(obj, index), indentLevel + 1);
                    std::cout << std::endl;
                }
                std::cout << GString(4 * indentLevel, ' ') << "}";
            }
        }
    };

    // Partially specialize TypeResolver<> for std::vectors:
    template <typename T>
    class GResolver<GVector<T>>
    {
    public:
        static GType *get()
        {
            static TypeVector typeDesc{static_cast<T *>(nullptr)};
            return &typeDesc;
        }
    };

}