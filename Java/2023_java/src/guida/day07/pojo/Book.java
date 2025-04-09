package guida.day07.pojo;

import java.math.BigDecimal;

public class Book {
    private int bookId;
    private String bookName;
    private String author;
    private String type;
    private BigDecimal price;
    private String description;

    public Book() {
    }

    public Book(int bookId, String bookName, String author, String type, BigDecimal price, String description) {
        this.bookId = bookId;
        this.bookName = bookName;
        this.author = author;
        this.type = type;
        this.price = price;
        this.description = description;
    }

    /**
     * 获取
     * @return bookId
     */
    public int getBookId() {
        return bookId;
    }

    /**
     * 设置
     * @param bookId
     */
    public void setBookId(int bookId) {
        this.bookId = bookId;
    }

    /**
     * 获取
     * @return bookName
     */
    public String getBookName() {
        return bookName;
    }

    /**
     * 设置
     * @param bookName
     */
    public void setBookName(String bookName) {
        this.bookName = bookName;
    }

    /**
     * 获取
     * @return author
     */
    public String getAuthor() {
        return author;
    }

    /**
     * 设置
     * @param author
     */
    public void setAuthor(String author) {
        this.author = author;
    }

    /**
     * 获取
     * @return type
     */
    public String getType() {
        return type;
    }

    /**
     * 设置
     * @param type
     */
    public void setType(String type) {
        this.type = type;
    }

    /**
     * 获取
     * @return price
     */
    public BigDecimal getPrice() {
        return price;
    }

    /**
     * 设置
     * @param price
     */
    public void setPrice(BigDecimal price) {
        this.price = price;
    }

    /**
     * 获取
     * @return description
     */
    public String getDescription() {
        return description;
    }

    /**
     * 设置
     * @param description
     */
    public void setDescription(String description) {
        this.description = description;
    }

    public String toString() {
        return "Book{bookId = " + bookId + ", bookName = " + bookName + ", author = " + author + ", type = " + type + ", price = " + price + ", description = " + description + "}";
    }
}
