# Queue implementation using array

class Queue
  def initialize
    @queue = []
  end

  def enqueue(item)
    @queue.push(item)
  end

  def dequeue
    @queue.shift
  end

  def front
    @queue.first
  end

  def rear
    @queue.last
  end

  def size
    @queue.size
  end

  def is_empty
    @queue.empty?
  end

  def display
    puts @queue
  end
end

if __FILE__ == $0
  queue = Queue.new
  queue.enqueue(10)
  queue.enqueue(20)
  queue.enqueue(30)
  queue.enqueue(40)
  queue.display
  puts queue.front
  puts queue.rear
  queue.dequeue
  queue.display
  puts queue.size
  puts queue.is_empty
end

