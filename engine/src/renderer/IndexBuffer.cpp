#include "ocf/renderer/IndexBuffer.h"

#include "ocf/scene/Engine.h"
#include "ocf/renderer/backend/Driver.h"
#include "renderer/backend/DriverBase.h"

namespace ocf {

using namespace backend;

IndexBuffer* IndexBuffer::create(IndexType type, uint32_t indexCount)
{
    IndexBuffer* indexBuffer = new IndexBuffer();
    if (indexBuffer->init(type, indexCount)) {
        return indexBuffer;
    }

    delete indexBuffer;
    return nullptr;
}

IndexBuffer::IndexBuffer()
    : m_handle(0)
    , m_indexCount(0)
    , m_indexType(IndexType::USHORT)
{
}

IndexBuffer::~IndexBuffer()
{
}

bool IndexBuffer::init(IndexType indexType, uint32_t indexCount)
{
    m_indexType = indexType;
    m_indexCount = indexCount;
    return true;
}

void IndexBuffer::createBuffer(Engine& engine)
{
    Driver* driver = engine.getDriver();
    m_handle = driver->createIndexBuffer(static_cast<ElementType>(m_indexType),
                                         m_indexCount, backend::BufferUsage::STATIC);
}

void IndexBuffer::setBufferData(Engine& engine, const void* data, size_t size, size_t offset)
{
    engine.getDriver()->updateIndexBufferData(m_handle, data, size, offset);
}

} // namespace ocf
