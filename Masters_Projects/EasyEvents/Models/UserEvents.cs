using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace EasyEvents.Models
{
    public class UserEvents
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int UserEventId { get; set; }
        public string RFIDTagId { get; set; }
        public int EventId { get; set; }
        public int GuestId { get; set; }
        public virtual Events Events { get; set; }
        public virtual Users Users { get; set; }
        public string IsAttended { get; set; }
    }
}
