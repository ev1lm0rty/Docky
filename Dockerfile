FROM php:apache
ADD ./Binary /
COPY ./Website/index.html /var/www/html/index.html
WORKDIR /Binary
CMD ["./docky"]
