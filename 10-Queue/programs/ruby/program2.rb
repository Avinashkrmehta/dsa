# Implementation of circular queue using array

class CircularQueue
  def initialize(size)
    @queue = Array.new(size)
    @front = -1
    @rear = -1
    @size = size
  end

  def enqueue(item)
    if (@front == 0 && @rear == @size - 1) || (@rear == (@front - 1) % (@size - 1))
      puts "Queue is full"
    elsif @front == -1
      @front = 0
      @rear = 0
      @queue[@rear] = item
    elsif @rear == @size - 1 && @front != 0
      @rear = 0
      @queue[@rear] = item
    else
      @rear = @rear + 1
      @queue[@rear] = item
    end
  end

  def dequeue
    if @front == -1
      puts "Queue is empty"
    end

    item = @queue[@front]
    @queue[@front] = nil

    if @front == @rear
      @front = -1
      @rear = -1
    elsif @front == @size - 1
      @front = 0
    else
      @front = @front + 1
    end

    item
  end

  def front
    @queue[@front]
  end

  def rear
    @queue[@rear]
  end

  def size
    @queue.size
  end

  def is_empty
    @front == -1
  end

  def display
    puts @queue
  end
end

if __FILE__ == $0
  queue = CircularQueue.new(5)
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
